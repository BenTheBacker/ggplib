#include "player/node.h"

#include "statemachine/statemachine.h"
#include "statemachine/jointmove.h"
#include "statemachine/basestate.h"

#include <k273/strutils.h>
#include <k273/exception.h>
#include <k273/logging.h>

using namespace std;
using namespace GGPLib;

static string moveString(const JointMove& move, StateMachineInterface* sm) {
    const int role_count = sm->getRoleCount();

    string res = "(";
    for (int ii=0; ii<role_count; ii++) {
        if (ii > 0) {
            res += " ";
        }

        int choice = move.get(ii);
        res += sm->legalToMove(ii, choice);
    }

    res += ")";

    return res;
}

static string scoreString(const Node* node, StateMachineInterface* sm) {
    const int role_count = sm->getRoleCount();
    string res = "(";
    for (int ii=0; ii<role_count; ii++) {
        if (ii > 0) {
            res += " ";
        }

        res += K273::fmtString("%.4f", node->getScore(ii));
    }

    res += ")";

    return res;
}

///////////////////////////////////////////////////////////////////////////////

static Node* createNode(const BaseState* base_state,
                        bool is_finalised,
                        int lead_role_index,
                        double select_ucb_constant,
                        int num_children,
                        int role_count) {

#define round_up_4(x) ((((x) / 4) + 1) * 4)

    const int child_size = sizeof(NodeChild);
    int score_bytes = round_up_4(role_count * sizeof(Score));
    int base_state_bytes = round_up_4(sizeof(BaseState) + base_state->byte_count);

    // remember that the JointMove is inline, so we only need to count the indices
    int node_child_bytes = round_up_4(child_size + sizeof(JointMove::IndexType) * role_count);

#undef round_up_4
    int total_bytes = sizeof(Node) + score_bytes + base_state_bytes + (num_children * node_child_bytes);

    //k_debug("total_bytes %d #child %d (%d / %d / %d)", total_bytes, num_children, score_bytes, base_state_bytes, (num_children * node_child_bytes));

    Node* node = static_cast<Node*> (malloc(total_bytes));
    node->visits = 0;
    node->sqrt_log_visits = 1;
    node->select_ucb_constant = select_ucb_constant;
    node->inflight_visits = 0;

    node->ref_count = 1;
    node->is_finalised = is_finalised;
    node->lead_role_index = lead_role_index;
    node->expected_depth = 0.0;
    node->num_children = num_children;
    node->unselectable_count = 0;

    node->basestate_ptr_incr = score_bytes;
    node->children_ptr_incr = score_bytes + base_state_bytes;

    // store the allocated size
    node->allocated_size = total_bytes;

    // initialise all scores to zero
    for (int ii=0; ii<role_count; ii++) {
        node->setScore(ii, 0.0);
    }

    // copy the base state
    BaseState* node_bs = node->getBaseState();
    node_bs->init(base_state->size);
    node_bs->assign(base_state);

    // children initialised in initialiseChildHelper()...
    return node;
}

static int initialiseChildHelper(Node* node, int role_index, int child_index,
                                 int role_count, StateMachineInterface* sm, JointMove* joint_move) {

    LegalState* ls = sm->getLegalState(role_index);
    bool final_role = role_index == role_count - 1;

    for (int ii=0; ii<ls->getCount(); ii++) {
        int choice = ls->getLegal(ii);
        joint_move->set(role_index, choice);

        if (final_role) {
            NodeChild* child = node->getNodeChild(role_count, child_index++);
            child->to_node = nullptr;
            child->unselectable = false;
            child->traversals = 0;
            child->inv_sqrt_traversals = 1.0;
            child->move.setSize(role_count);
            child->move.assign(joint_move);

        } else {
            // recurses, needs to set children
            child_index = initialiseChildHelper(node, role_index + 1,
                                                child_index, role_count, sm, joint_move);
        }
    }

    return child_index;
}


// This is a static method.
Node* Node::create(int role_count,
                   int our_role_index,
                   double select_ucb_constant,
                   const BaseState* base_state,
                   StateMachineInterface* sm) {

    sm->updateBases(base_state);

    bool is_finalised = true;
    int total_children = 0;
    int lead_role_index = our_role_index;
    if (!sm->isTerminal()) {

        total_children = 1;
        is_finalised = false;

        // how many children do we need? (effectively a cross product)
        int max_moves_for_a_role = 1;
        for (int ri=0; ri<role_count; ri++) {
            LegalState* ls = sm->getLegalState(ri);
            total_children *= ls->getCount();
            if (ls->getCount() > max_moves_for_a_role) {
                max_moves_for_a_role = ls->getCount();
                lead_role_index = ri;
            }
        }

        //k_debug("total %d", total_children);
        if (max_moves_for_a_role > 1) {

            // note lead_role_index could be any player at this point

            // are the rest 1?
            bool rest_one = true;
            for (int ri=0; ri<role_count; ri++) {
                LegalState* ls = sm->getLegalState(ri);
                if (ri != lead_role_index && ls->getCount() > 1) {
                    rest_one = false;
                }
            }

            // simultaneous?
            if (!rest_one) {
                lead_role_index = LEAD_ROLE_INDEX_SIMULTANEOUS;
            }
        }

    } else {
        // XXX I don't think we have to do anything.  The score will be updated by the updater as we add the new node.
        //k_debug("node is final");
    }

    //k_debug("before createNode total_children %d", total_children);

    Node* node = createNode(base_state,
                            is_finalised,
                            lead_role_index,
                            select_ucb_constant,
                            total_children,
                            role_count);
    if (!node->is_finalised) {
        char buf[JointMove::mallocSize(role_count)];
        JointMove* move = (JointMove*) buf;
        int count = initialiseChildHelper(node, 0, 0, role_count, sm, move);
        ASSERT (count == total_children);
    }

    return node;
}

///////////////////////////////////////////////////////////////////////////////

void Node::dumpNode(const Node* node, const NodeChild* highlight,
                    const std::string& indent, StateMachineInterface* sm) {

    int role_count = sm->getRoleCount();

    double total_score = 0;
    for (int ii=0; ii<role_count; ii++) {
        total_score += node->getScore(ii);
    }

    string finalised_top = node->is_finalised ? "[Final]" : ".";
    K273::l_debug("%s(%d) :: %s == %.4f / #childs %d, ucb %.2f / %s / depth: %.2f / Lead : %d",
                  indent.c_str(),
                  node->visits,
                  scoreString(node, sm).c_str(),
                  total_score,
                  node->num_children,
                  node->select_ucb_constant,
                  finalised_top.c_str(),
                  node->expected_depth,
                  node->lead_role_index);

    for (int ii=0; ii<node->num_children; ii++) {
        const NodeChild* child = node->getNodeChild(role_count, ii);

        if (child->to_node != nullptr) {
            string finalised = child->to_node->is_finalised ? "[Final]" : ".";

            if (child == highlight) {
                K273::l_info("%sMove %s score %s / visits %d/%d / %s",
                             indent.c_str(),
                             moveString(child->move, sm).c_str(),
                             scoreString(child->to_node, sm).c_str(),
                             child->traversals,
                             child->to_node->visits,
                             finalised.c_str());
            } else {
                K273::l_debug("%sMove %s score %s / visits %d/%d / %s",
                              indent.c_str(),
                              moveString(child->move, sm).c_str(),
                              scoreString(child->to_node, sm).c_str(),
                              child->traversals,
                              child->to_node->visits,
                              finalised.c_str());
            }

        } else {
            if (child == highlight) {
                K273::l_info("%sMove %s score - / visits - %d / .",
                             indent.c_str(), moveString(child->move, sm).c_str(), child->traversals);
            } else {
                K273::l_debug("%sMove %s score - / visits - %d / .",
                              indent.c_str(), moveString(child->move, sm).c_str(), child->traversals);
            }
        }
    }
}
