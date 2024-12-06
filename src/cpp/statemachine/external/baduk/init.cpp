// WARNING XXX this has been hand tweaked... :(  Need to fix up the code gen script.

// local includes
#include "desc.h"
#include "board.h"

// k273 includes
#include <k273/util.h>
#include <k273/logging.h>
#include <k273/exception.h>

using namespace Baduk;




void Description::initBoard_9x9() {

    this->komi = 7.0;

    // Initial state
    this->initial_state = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false};



    // generating moves for black
    this->black_legal_moves = {"noop", "pass", "(place a 1)", "(place a 2)", "(place a 3)", "(place a 4)", "(place a 5)", "(place a 6)", "(place a 7)", "(place a 8)", "(place a 9)", "(place b 1)", "(place b 2)", "(place b 3)", "(place b 4)", "(place b 5)", "(place b 6)", "(place b 7)", "(place b 8)", "(place b 9)", "(place c 1)", "(place c 2)", "(place c 3)", "(place c 4)", "(place c 5)", "(place c 6)", "(place c 7)", "(place c 8)", "(place c 9)", "(place d 1)", "(place d 2)", "(place d 3)", "(place d 4)", "(place d 5)", "(place d 6)", "(place d 7)", "(place d 8)", "(place d 9)", "(place e 1)", "(place e 2)", "(place e 3)", "(place e 4)", "(place e 5)", "(place e 6)", "(place e 7)", "(place e 8)", "(place e 9)", "(place f 1)", "(place f 2)", "(place f 3)", "(place f 4)", "(place f 5)", "(place f 6)", "(place f 7)", "(place f 8)", "(place f 9)", "(place g 1)", "(place g 2)", "(place g 3)", "(place g 4)", "(place g 5)", "(place g 6)", "(place g 7)", "(place g 8)", "(place g 9)", "(place h 1)", "(place h 2)", "(place h 3)", "(place h 4)", "(place h 5)", "(place h 6)", "(place h 7)", "(place h 8)", "(place h 9)", "(place i 1)", "(place i 2)", "(place i 3)", "(place i 4)", "(place i 5)", "(place i 6)", "(place i 7)", "(place i 8)", "(place i 9)"};

    // generating moves for white
    this->white_legal_moves = {"noop", "pass", "(place a 1)", "(place a 2)", "(place a 3)", "(place a 4)", "(place a 5)", "(place a 6)", "(place a 7)", "(place a 8)", "(place a 9)", "(place b 1)", "(place b 2)", "(place b 3)", "(place b 4)", "(place b 5)", "(place b 6)", "(place b 7)", "(place b 8)", "(place b 9)", "(place c 1)", "(place c 2)", "(place c 3)", "(place c 4)", "(place c 5)", "(place c 6)", "(place c 7)", "(place c 8)", "(place c 9)", "(place d 1)", "(place d 2)", "(place d 3)", "(place d 4)", "(place d 5)", "(place d 6)", "(place d 7)", "(place d 8)", "(place d 9)", "(place e 1)", "(place e 2)", "(place e 3)", "(place e 4)", "(place e 5)", "(place e 6)", "(place e 7)", "(place e 8)", "(place e 9)", "(place f 1)", "(place f 2)", "(place f 3)", "(place f 4)", "(place f 5)", "(place f 6)", "(place f 7)", "(place f 8)", "(place f 9)", "(place g 1)", "(place g 2)", "(place g 3)", "(place g 4)", "(place g 5)", "(place g 6)", "(place g 7)", "(place g 8)", "(place g 9)", "(place h 1)", "(place h 2)", "(place h 3)", "(place h 4)", "(place h 5)", "(place h 6)", "(place h 7)", "(place h 8)", "(place h 9)", "(place i 1)", "(place i 2)", "(place i 3)", "(place i 4)", "(place i 5)", "(place i 6)", "(place i 7)", "(place i 8)", "(place i 9)"};


} // end of BoardDescription::initBoard_19x19

void Description::initBoard_13x13() {

    this->komi = 7.5;

    // Initial state
    this->initial_state = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false};



    // generating moves for black
    this->black_legal_moves = {"noop", "pass", "(place a 1)", "(place a 2)", "(place a 3)", "(place a 4)", "(place a 5)", "(place a 6)", "(place a 7)", "(place a 8)", "(place a 9)", "(place a 10)", "(place a 11)", "(place a 12)", "(place a 13)", "(place b 1)", "(place b 2)", "(place b 3)", "(place b 4)", "(place b 5)", "(place b 6)", "(place b 7)", "(place b 8)", "(place b 9)", "(place b 10)", "(place b 11)", "(place b 12)", "(place b 13)", "(place c 1)", "(place c 2)", "(place c 3)", "(place c 4)", "(place c 5)", "(place c 6)", "(place c 7)", "(place c 8)", "(place c 9)", "(place c 10)", "(place c 11)", "(place c 12)", "(place c 13)", "(place d 1)", "(place d 2)", "(place d 3)", "(place d 4)", "(place d 5)", "(place d 6)", "(place d 7)", "(place d 8)", "(place d 9)", "(place d 10)", "(place d 11)", "(place d 12)", "(place d 13)", "(place e 1)", "(place e 2)", "(place e 3)", "(place e 4)", "(place e 5)", "(place e 6)", "(place e 7)", "(place e 8)", "(place e 9)", "(place e 10)", "(place e 11)", "(place e 12)", "(place e 13)", "(place f 1)", "(place f 2)", "(place f 3)", "(place f 4)", "(place f 5)", "(place f 6)", "(place f 7)", "(place f 8)", "(place f 9)", "(place f 10)", "(place f 11)", "(place f 12)", "(place f 13)", "(place g 1)", "(place g 2)", "(place g 3)", "(place g 4)", "(place g 5)", "(place g 6)", "(place g 7)", "(place g 8)", "(place g 9)", "(place g 10)", "(place g 11)", "(place g 12)", "(place g 13)", "(place h 1)", "(place h 2)", "(place h 3)", "(place h 4)", "(place h 5)", "(place h 6)", "(place h 7)", "(place h 8)", "(place h 9)", "(place h 10)", "(place h 11)", "(place h 12)", "(place h 13)", "(place i 1)", "(place i 2)", "(place i 3)", "(place i 4)", "(place i 5)", "(place i 6)", "(place i 7)", "(place i 8)", "(place i 9)", "(place i 10)", "(place i 11)", "(place i 12)", "(place i 13)", "(place j 1)", "(place j 2)", "(place j 3)", "(place j 4)", "(place j 5)", "(place j 6)", "(place j 7)", "(place j 8)", "(place j 9)", "(place j 10)", "(place j 11)", "(place j 12)", "(place j 13)", "(place k 1)", "(place k 2)", "(place k 3)", "(place k 4)", "(place k 5)", "(place k 6)", "(place k 7)", "(place k 8)", "(place k 9)", "(place k 10)", "(place k 11)", "(place k 12)", "(place k 13)", "(place l 1)", "(place l 2)", "(place l 3)", "(place l 4)", "(place l 5)", "(place l 6)", "(place l 7)", "(place l 8)", "(place l 9)", "(place l 10)", "(place l 11)", "(place l 12)", "(place l 13)", "(place m 1)", "(place m 2)", "(place m 3)", "(place m 4)", "(place m 5)", "(place m 6)", "(place m 7)", "(place m 8)", "(place m 9)", "(place m 10)", "(place m 11)", "(place m 12)", "(place m 13)"};

    // generating moves for white
    this->white_legal_moves = {"noop", "pass", "(place a 1)", "(place a 2)", "(place a 3)", "(place a 4)", "(place a 5)", "(place a 6)", "(place a 7)", "(place a 8)", "(place a 9)", "(place a 10)", "(place a 11)", "(place a 12)", "(place a 13)", "(place b 1)", "(place b 2)", "(place b 3)", "(place b 4)", "(place b 5)", "(place b 6)", "(place b 7)", "(place b 8)", "(place b 9)", "(place b 10)", "(place b 11)", "(place b 12)", "(place b 13)", "(place c 1)", "(place c 2)", "(place c 3)", "(place c 4)", "(place c 5)", "(place c 6)", "(place c 7)", "(place c 8)", "(place c 9)", "(place c 10)", "(place c 11)", "(place c 12)", "(place c 13)", "(place d 1)", "(place d 2)", "(place d 3)", "(place d 4)", "(place d 5)", "(place d 6)", "(place d 7)", "(place d 8)", "(place d 9)", "(place d 10)", "(place d 11)", "(place d 12)", "(place d 13)", "(place e 1)", "(place e 2)", "(place e 3)", "(place e 4)", "(place e 5)", "(place e 6)", "(place e 7)", "(place e 8)", "(place e 9)", "(place e 10)", "(place e 11)", "(place e 12)", "(place e 13)", "(place f 1)", "(place f 2)", "(place f 3)", "(place f 4)", "(place f 5)", "(place f 6)", "(place f 7)", "(place f 8)", "(place f 9)", "(place f 10)", "(place f 11)", "(place f 12)", "(place f 13)", "(place g 1)", "(place g 2)", "(place g 3)", "(place g 4)", "(place g 5)", "(place g 6)", "(place g 7)", "(place g 8)", "(place g 9)", "(place g 10)", "(place g 11)", "(place g 12)", "(place g 13)", "(place h 1)", "(place h 2)", "(place h 3)", "(place h 4)", "(place h 5)", "(place h 6)", "(place h 7)", "(place h 8)", "(place h 9)", "(place h 10)", "(place h 11)", "(place h 12)", "(place h 13)", "(place i 1)", "(place i 2)", "(place i 3)", "(place i 4)", "(place i 5)", "(place i 6)", "(place i 7)", "(place i 8)", "(place i 9)", "(place i 10)", "(place i 11)", "(place i 12)", "(place i 13)", "(place j 1)", "(place j 2)", "(place j 3)", "(place j 4)", "(place j 5)", "(place j 6)", "(place j 7)", "(place j 8)", "(place j 9)", "(place j 10)", "(place j 11)", "(place j 12)", "(place j 13)", "(place k 1)", "(place k 2)", "(place k 3)", "(place k 4)", "(place k 5)", "(place k 6)", "(place k 7)", "(place k 8)", "(place k 9)", "(place k 10)", "(place k 11)", "(place k 12)", "(place k 13)", "(place l 1)", "(place l 2)", "(place l 3)", "(place l 4)", "(place l 5)", "(place l 6)", "(place l 7)", "(place l 8)", "(place l 9)", "(place l 10)", "(place l 11)", "(place l 12)", "(place l 13)", "(place m 1)", "(place m 2)", "(place m 3)", "(place m 4)", "(place m 5)", "(place m 6)", "(place m 7)", "(place m 8)", "(place m 9)", "(place m 10)", "(place m 11)", "(place m 12)", "(place m 13)"};


} // end of BoardDescription::initBoard_19x19

void Description::initBoard_19x19() {

    this->komi = 7.5;

    // Initial state
    this->initial_state = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false};



    // generating moves for black
    this->black_legal_moves = {"noop", "pass", "(place a 1)", "(place a 2)", "(place a 3)", "(place a 4)", "(place a 5)", "(place a 6)", "(place a 7)", "(place a 8)", "(place a 9)", "(place a 10)", "(place a 11)", "(place a 12)", "(place a 13)", "(place a 14)", "(place a 15)", "(place a 16)", "(place a 17)", "(place a 18)", "(place a 19)", "(place b 1)", "(place b 2)", "(place b 3)", "(place b 4)", "(place b 5)", "(place b 6)", "(place b 7)", "(place b 8)", "(place b 9)", "(place b 10)", "(place b 11)", "(place b 12)", "(place b 13)", "(place b 14)", "(place b 15)", "(place b 16)", "(place b 17)", "(place b 18)", "(place b 19)", "(place c 1)", "(place c 2)", "(place c 3)", "(place c 4)", "(place c 5)", "(place c 6)", "(place c 7)", "(place c 8)", "(place c 9)", "(place c 10)", "(place c 11)", "(place c 12)", "(place c 13)", "(place c 14)", "(place c 15)", "(place c 16)", "(place c 17)", "(place c 18)", "(place c 19)", "(place d 1)", "(place d 2)", "(place d 3)", "(place d 4)", "(place d 5)", "(place d 6)", "(place d 7)", "(place d 8)", "(place d 9)", "(place d 10)", "(place d 11)", "(place d 12)", "(place d 13)", "(place d 14)", "(place d 15)", "(place d 16)", "(place d 17)", "(place d 18)", "(place d 19)", "(place e 1)", "(place e 2)", "(place e 3)", "(place e 4)", "(place e 5)", "(place e 6)", "(place e 7)", "(place e 8)", "(place e 9)", "(place e 10)", "(place e 11)", "(place e 12)", "(place e 13)", "(place e 14)", "(place e 15)", "(place e 16)", "(place e 17)", "(place e 18)", "(place e 19)", "(place f 1)", "(place f 2)", "(place f 3)", "(place f 4)", "(place f 5)", "(place f 6)", "(place f 7)", "(place f 8)", "(place f 9)", "(place f 10)", "(place f 11)", "(place f 12)", "(place f 13)", "(place f 14)", "(place f 15)", "(place f 16)", "(place f 17)", "(place f 18)", "(place f 19)", "(place g 1)", "(place g 2)", "(place g 3)", "(place g 4)", "(place g 5)", "(place g 6)", "(place g 7)", "(place g 8)", "(place g 9)", "(place g 10)", "(place g 11)", "(place g 12)", "(place g 13)", "(place g 14)", "(place g 15)", "(place g 16)", "(place g 17)", "(place g 18)", "(place g 19)", "(place h 1)", "(place h 2)", "(place h 3)", "(place h 4)", "(place h 5)", "(place h 6)", "(place h 7)", "(place h 8)", "(place h 9)", "(place h 10)", "(place h 11)", "(place h 12)", "(place h 13)", "(place h 14)", "(place h 15)", "(place h 16)", "(place h 17)", "(place h 18)", "(place h 19)", "(place i 1)", "(place i 2)", "(place i 3)", "(place i 4)", "(place i 5)", "(place i 6)", "(place i 7)", "(place i 8)", "(place i 9)", "(place i 10)", "(place i 11)", "(place i 12)", "(place i 13)", "(place i 14)", "(place i 15)", "(place i 16)", "(place i 17)", "(place i 18)", "(place i 19)", "(place j 1)", "(place j 2)", "(place j 3)", "(place j 4)", "(place j 5)", "(place j 6)", "(place j 7)", "(place j 8)", "(place j 9)", "(place j 10)", "(place j 11)", "(place j 12)", "(place j 13)", "(place j 14)", "(place j 15)", "(place j 16)", "(place j 17)", "(place j 18)", "(place j 19)", "(place k 1)", "(place k 2)", "(place k 3)", "(place k 4)", "(place k 5)", "(place k 6)", "(place k 7)", "(place k 8)", "(place k 9)", "(place k 10)", "(place k 11)", "(place k 12)", "(place k 13)", "(place k 14)", "(place k 15)", "(place k 16)", "(place k 17)", "(place k 18)", "(place k 19)", "(place l 1)", "(place l 2)", "(place l 3)", "(place l 4)", "(place l 5)", "(place l 6)", "(place l 7)", "(place l 8)", "(place l 9)", "(place l 10)", "(place l 11)", "(place l 12)", "(place l 13)", "(place l 14)", "(place l 15)", "(place l 16)", "(place l 17)", "(place l 18)", "(place l 19)", "(place m 1)", "(place m 2)", "(place m 3)", "(place m 4)", "(place m 5)", "(place m 6)", "(place m 7)", "(place m 8)", "(place m 9)", "(place m 10)", "(place m 11)", "(place m 12)", "(place m 13)", "(place m 14)", "(place m 15)", "(place m 16)", "(place m 17)", "(place m 18)", "(place m 19)", "(place n 1)", "(place n 2)", "(place n 3)", "(place n 4)", "(place n 5)", "(place n 6)", "(place n 7)", "(place n 8)", "(place n 9)", "(place n 10)", "(place n 11)", "(place n 12)", "(place n 13)", "(place n 14)", "(place n 15)", "(place n 16)", "(place n 17)", "(place n 18)", "(place n 19)", "(place o 1)", "(place o 2)", "(place o 3)", "(place o 4)", "(place o 5)", "(place o 6)", "(place o 7)", "(place o 8)", "(place o 9)", "(place o 10)", "(place o 11)", "(place o 12)", "(place o 13)", "(place o 14)", "(place o 15)", "(place o 16)", "(place o 17)", "(place o 18)", "(place o 19)", "(place p 1)", "(place p 2)", "(place p 3)", "(place p 4)", "(place p 5)", "(place p 6)", "(place p 7)", "(place p 8)", "(place p 9)", "(place p 10)", "(place p 11)", "(place p 12)", "(place p 13)", "(place p 14)", "(place p 15)", "(place p 16)", "(place p 17)", "(place p 18)", "(place p 19)", "(place q 1)", "(place q 2)", "(place q 3)", "(place q 4)", "(place q 5)", "(place q 6)", "(place q 7)", "(place q 8)", "(place q 9)", "(place q 10)", "(place q 11)", "(place q 12)", "(place q 13)", "(place q 14)", "(place q 15)", "(place q 16)", "(place q 17)", "(place q 18)", "(place q 19)", "(place r 1)", "(place r 2)", "(place r 3)", "(place r 4)", "(place r 5)", "(place r 6)", "(place r 7)", "(place r 8)", "(place r 9)", "(place r 10)", "(place r 11)", "(place r 12)", "(place r 13)", "(place r 14)", "(place r 15)", "(place r 16)", "(place r 17)", "(place r 18)", "(place r 19)", "(place s 1)", "(place s 2)", "(place s 3)", "(place s 4)", "(place s 5)", "(place s 6)", "(place s 7)", "(place s 8)", "(place s 9)", "(place s 10)", "(place s 11)", "(place s 12)", "(place s 13)", "(place s 14)", "(place s 15)", "(place s 16)", "(place s 17)", "(place s 18)", "(place s 19)"};

    // generating moves for white
    this->white_legal_moves = {"noop", "pass", "(place a 1)", "(place a 2)", "(place a 3)", "(place a 4)", "(place a 5)", "(place a 6)", "(place a 7)", "(place a 8)", "(place a 9)", "(place a 10)", "(place a 11)", "(place a 12)", "(place a 13)", "(place a 14)", "(place a 15)", "(place a 16)", "(place a 17)", "(place a 18)", "(place a 19)", "(place b 1)", "(place b 2)", "(place b 3)", "(place b 4)", "(place b 5)", "(place b 6)", "(place b 7)", "(place b 8)", "(place b 9)", "(place b 10)", "(place b 11)", "(place b 12)", "(place b 13)", "(place b 14)", "(place b 15)", "(place b 16)", "(place b 17)", "(place b 18)", "(place b 19)", "(place c 1)", "(place c 2)", "(place c 3)", "(place c 4)", "(place c 5)", "(place c 6)", "(place c 7)", "(place c 8)", "(place c 9)", "(place c 10)", "(place c 11)", "(place c 12)", "(place c 13)", "(place c 14)", "(place c 15)", "(place c 16)", "(place c 17)", "(place c 18)", "(place c 19)", "(place d 1)", "(place d 2)", "(place d 3)", "(place d 4)", "(place d 5)", "(place d 6)", "(place d 7)", "(place d 8)", "(place d 9)", "(place d 10)", "(place d 11)", "(place d 12)", "(place d 13)", "(place d 14)", "(place d 15)", "(place d 16)", "(place d 17)", "(place d 18)", "(place d 19)", "(place e 1)", "(place e 2)", "(place e 3)", "(place e 4)", "(place e 5)", "(place e 6)", "(place e 7)", "(place e 8)", "(place e 9)", "(place e 10)", "(place e 11)", "(place e 12)", "(place e 13)", "(place e 14)", "(place e 15)", "(place e 16)", "(place e 17)", "(place e 18)", "(place e 19)", "(place f 1)", "(place f 2)", "(place f 3)", "(place f 4)", "(place f 5)", "(place f 6)", "(place f 7)", "(place f 8)", "(place f 9)", "(place f 10)", "(place f 11)", "(place f 12)", "(place f 13)", "(place f 14)", "(place f 15)", "(place f 16)", "(place f 17)", "(place f 18)", "(place f 19)", "(place g 1)", "(place g 2)", "(place g 3)", "(place g 4)", "(place g 5)", "(place g 6)", "(place g 7)", "(place g 8)", "(place g 9)", "(place g 10)", "(place g 11)", "(place g 12)", "(place g 13)", "(place g 14)", "(place g 15)", "(place g 16)", "(place g 17)", "(place g 18)", "(place g 19)", "(place h 1)", "(place h 2)", "(place h 3)", "(place h 4)", "(place h 5)", "(place h 6)", "(place h 7)", "(place h 8)", "(place h 9)", "(place h 10)", "(place h 11)", "(place h 12)", "(place h 13)", "(place h 14)", "(place h 15)", "(place h 16)", "(place h 17)", "(place h 18)", "(place h 19)", "(place i 1)", "(place i 2)", "(place i 3)", "(place i 4)", "(place i 5)", "(place i 6)", "(place i 7)", "(place i 8)", "(place i 9)", "(place i 10)", "(place i 11)", "(place i 12)", "(place i 13)", "(place i 14)", "(place i 15)", "(place i 16)", "(place i 17)", "(place i 18)", "(place i 19)", "(place j 1)", "(place j 2)", "(place j 3)", "(place j 4)", "(place j 5)", "(place j 6)", "(place j 7)", "(place j 8)", "(place j 9)", "(place j 10)", "(place j 11)", "(place j 12)", "(place j 13)", "(place j 14)", "(place j 15)", "(place j 16)", "(place j 17)", "(place j 18)", "(place j 19)", "(place k 1)", "(place k 2)", "(place k 3)", "(place k 4)", "(place k 5)", "(place k 6)", "(place k 7)", "(place k 8)", "(place k 9)", "(place k 10)", "(place k 11)", "(place k 12)", "(place k 13)", "(place k 14)", "(place k 15)", "(place k 16)", "(place k 17)", "(place k 18)", "(place k 19)", "(place l 1)", "(place l 2)", "(place l 3)", "(place l 4)", "(place l 5)", "(place l 6)", "(place l 7)", "(place l 8)", "(place l 9)", "(place l 10)", "(place l 11)", "(place l 12)", "(place l 13)", "(place l 14)", "(place l 15)", "(place l 16)", "(place l 17)", "(place l 18)", "(place l 19)", "(place m 1)", "(place m 2)", "(place m 3)", "(place m 4)", "(place m 5)", "(place m 6)", "(place m 7)", "(place m 8)", "(place m 9)", "(place m 10)", "(place m 11)", "(place m 12)", "(place m 13)", "(place m 14)", "(place m 15)", "(place m 16)", "(place m 17)", "(place m 18)", "(place m 19)", "(place n 1)", "(place n 2)", "(place n 3)", "(place n 4)", "(place n 5)", "(place n 6)", "(place n 7)", "(place n 8)", "(place n 9)", "(place n 10)", "(place n 11)", "(place n 12)", "(place n 13)", "(place n 14)", "(place n 15)", "(place n 16)", "(place n 17)", "(place n 18)", "(place n 19)", "(place o 1)", "(place o 2)", "(place o 3)", "(place o 4)", "(place o 5)", "(place o 6)", "(place o 7)", "(place o 8)", "(place o 9)", "(place o 10)", "(place o 11)", "(place o 12)", "(place o 13)", "(place o 14)", "(place o 15)", "(place o 16)", "(place o 17)", "(place o 18)", "(place o 19)", "(place p 1)", "(place p 2)", "(place p 3)", "(place p 4)", "(place p 5)", "(place p 6)", "(place p 7)", "(place p 8)", "(place p 9)", "(place p 10)", "(place p 11)", "(place p 12)", "(place p 13)", "(place p 14)", "(place p 15)", "(place p 16)", "(place p 17)", "(place p 18)", "(place p 19)", "(place q 1)", "(place q 2)", "(place q 3)", "(place q 4)", "(place q 5)", "(place q 6)", "(place q 7)", "(place q 8)", "(place q 9)", "(place q 10)", "(place q 11)", "(place q 12)", "(place q 13)", "(place q 14)", "(place q 15)", "(place q 16)", "(place q 17)", "(place q 18)", "(place q 19)", "(place r 1)", "(place r 2)", "(place r 3)", "(place r 4)", "(place r 5)", "(place r 6)", "(place r 7)", "(place r 8)", "(place r 9)", "(place r 10)", "(place r 11)", "(place r 12)", "(place r 13)", "(place r 14)", "(place r 15)", "(place r 16)", "(place r 17)", "(place r 18)", "(place r 19)", "(place s 1)", "(place s 2)", "(place s 3)", "(place s 4)", "(place s 5)", "(place s 6)", "(place s 7)", "(place s 8)", "(place s 9)", "(place s 10)", "(place s 11)", "(place s 12)", "(place s 13)", "(place s 14)", "(place s 15)", "(place s 16)", "(place s 17)", "(place s 18)", "(place s 19)"};


} // end of BoardDescription::initBoard_19x19
// end of file
