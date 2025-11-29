#ifndef FINAL_REPO_LOCAL_PUZZLE_H
#define FINAL_REPO_LOCAL_PUZZLE_H


#include <functional>
#include "Game.h"

//Class for the puzzle type games
class Puzzle : public Game {

    private:
    int puzzleID;
    std::function<bool(Game*)> isSolved;

    public:
    //Constructor
    Puzzle(int id, std::function<bool(Game*)> solverFunc);


    //Getter for puzzle ID
    int getPuzzleID() const { return puzzleID; }

    //Solver function
    bool puzzleSolved(Game* game) {
        return isSolved(game);
    }


};

#endif //FINAL_REPO_LOCAL_PUZZLE_H