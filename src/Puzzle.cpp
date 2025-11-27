#include "Puzzle.h"
using namespace std;


Puzzle::Puzzle(int id, std::function<bool(Game *)> solverFunc)
    : Game(), puzzleID(0) {
    gameType = "Puzzle";
    isSolved = solverFunc;
}

Puzzle::~Puzzle() {}


