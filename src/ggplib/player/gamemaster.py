import random
from ggplib.util import log
from ggplib import interface

from ggplib.player.match import Match
from ggplib.util.symbols import SymbolFactory


# XXX match_id needs to be recreated each game

class GameMaster(object):
    def __init__(self, game_info, verbose=False, fast_reset=False):
        self.game_info = game_info
        self.verbose = verbose
        self.fast_reset = fast_reset

        # used to convert to base state
        self.symbol_factory = SymbolFactory()

        self.sm = self.game_info.get_sm()
        self.game = self.game_info.game
        self.match_id = None

        # store a joint move / basestate internally
        self.joint_move = self.sm.get_joint_move()
        self.next_basestate = self.sm.new_base_state()

        # XXX we really shouldn't need to do this... why not just use model??? XXX
        def get_base_tuple(i):
            return tuple(self.symbol_factory.to_symbols(game_info.model.bases[i]))[0]

        self.bases = [get_base_tuple(i) for i in range(self.next_basestate.len())]

        self.players = []
        self.players_map = {}

        # updated after game is finished
        self.scores = {}

        if verbose:
            log.info("GAMEMASTER: create a gamemaster for game %s" % self.game)

        self.matches = None

    def create_match_id(self):
        return "a_%s_match_id_%d" % (self.game, random.randint(0, 100000))

    def add_player(self, player, role):
        self.players.append((player, role))
        self.players_map[role] = player

    def get_player(self, role_index):
        return self.players[role_index][0]

    def get_score(self, role):
        return self.scores[role]

    def get_game_depth(self):
        # ask the first match what the depth is
        if self.matches:
            return self.matches[0].game_depth
        else:
            return -1

    def convert_to_base_state(self, state_str):
        state_set = set()
        for state in self.symbol_factory.to_symbols(state_str):
            state_set.add(state)

        bs = self.sm.new_base_state()
        for i in range(bs.len()):
            # we try both with 'x' and without '(true x)'
            if self.bases[i] in state_set or self.bases[i][1] in state_set:
                bs.set(i, 1)
            else:
                bs.set(i, 0)

        return bs

    def reset(self):
        self.scores = {}
        if not self.fast_reset:
            self.matches = None

    def start(self, meta_time=10, move_time=5, initial_basestate=None, game_depth=0):
        self.match_id = self.create_match_id()

        assert self.players

        if initial_basestate is not None:
            # update the state machine
            self.sm.update_bases(initial_basestate)

            # check the game isn't finished
            assert not self.sm.is_terminal()
        else:
            # reset state machine, returns it to initial state.
            self.sm.reset()

        if self.matches is None:
            player_matches = []
            for player, role in self.players:

                match = Match(self.game_info, self.match_id, role, meta_time, move_time,
                              player, verbose=self.verbose, no_cleanup=True)

                player_matches.append(match)

                # call do start...
                if self.verbose:
                    log.verbose("Starting for %s / %s" % (match.role, match.player))
                match.do_start(initial_basestate=initial_basestate, game_depth=game_depth)

            # reorder matches to roles (and check that we have them)
            self.matches = []
            for role in self.sm.get_roles():
                for match in player_matches:
                    if role == match.role:
                        self.matches.append(match)
                        break

            assert len(self.matches) == len(self.sm.get_roles())
        else:
            for (player, role), match in zip(self.players, self.matches):
                match.fast_reset(self.match_id, player, role)
                match.do_start(initial_basestate=initial_basestate, game_depth=game_depth)

    def play_single_move(self, last_move=None):
        assert not self.finished()

        actions = []
        new_last_move = []
        for role_index, (match, role) in enumerate(zip(self.matches, self.sm.get_roles())):
            if self.verbose:
                log.verbose("===============================================================")
                log.verbose(f"do_play({last_move}) for {role} / {match.player.get_name()}")

            # Check if a forced move is set for this role
            if role in self.forced_moves:
                forced_move = self.forced_moves[role]
                match.set_forced_move(forced_move)
                if self.verbose:
                    log.verbose(f"GameMaster: Forcing move '{forced_move}' for role '{role}'")

            move = match.do_play(last_move)
            new_last_move.append(move)

            # Check the move is in the legals
            ls = self.sm.get_legal_state(role_index)
            choices = [ls.get_legal(ii) for ii in range(ls.get_count())]

            for choice in choices:
                choice_move = self.sm.legal_to_move(role_index, choice)

                if choice_move == move:
                    self.joint_move.set(role_index, choice)
                    actions.append(move)
                    break

        assert len(actions) == len(self.matches)
        if self.verbose:
            log.verbose(f"playing {actions}")

        self.sm.next_state(self.joint_move, self.next_basestate)
        self.sm.update_bases(self.next_basestate)

        return tuple(new_last_move)

    def set_forced_move(self, role, move):
        ''' Sets a forced move for a specific role. '''
        if role not in self.players_map:
            raise ValueError(f"Role {role} does not exist.")
        self.forced_moves[role] = move
        if self.verbose:
            log.info(f"GameMaster: Forced move for role '{role}' set to '{move}'")

    def clear_forced_move(self, role):
        ''' Clears a forced move for a specific role. '''
        if role in self.forced_moves:
            del self.forced_moves[role]
            if self.verbose:
                log.info(f"GameMaster: Forced move for role '{role}' cleared")


    def finished(self):
        return self.sm.is_terminal()

    def finalise_match(self, last_move):
        if self.verbose:
            log.verbose("Played to depth %d" % self.get_game_depth())
            log.verbose("Last move %s" % (last_move,))

        for ri, role in enumerate(self.sm.get_roles()):
            score = self.sm.get_goal_value(ri)
            self.scores[role] = score
            if self.verbose:
                log.verbose("Final score for %s : %s " % (role, score))

        # Need to do the final move for player
        for match in self.matches:
            assert match.do_play(last_move) == "done"

            # and stop them
            match.do_stop()

    def play_to_end(self, last_move=None):
        while not self.finished():
            last_move = self.play_single_move(last_move)

        self.finalise_match(last_move)

    def cleanup(self, keep_sm=False):
        if self.next_basestate:
            interface.dealloc_basestate(self.next_basestate)
            self.next_basestate = None

        if self.joint_move:
            interface.dealloc_jointmove(self.joint_move)
            self.joint_move = None

        if not keep_sm and self.sm:
            interface.dealloc_statemachine(self.sm)
            self.sm = None
