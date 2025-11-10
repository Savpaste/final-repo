//
// Created by Avery Williams on 10/26/25.
//

#ifndef FINAL_REPO_LOCAL_PUZZLE_H
#define FINAL_REPO_LOCAL_PUZZLE_H


#include <functional>
#include "Game.h"

//Class for the puzzle type games
class Puzzle : public Game {

    private:
    int puzzleID;

    public:
    //Constructor and deconstructor
    Puzzle(int id, std::function<bool(Game*)> solverFunc);
    ~Puzzle();

    //Getter for puzzle ID
    int getPuzzleID() const { return puzzleID; }

    //Solver function
    std::function<bool(Game*)> isSolved;


};

#endif //FINAL_REPO_LOCAL_PUZZLE_H