//
// Created by Avery Williams on 10/26/25.
//

#ifndef FINAL_REPO_LOCAL_RIDDLE_H
#define FINAL_REPO_LOCAL_RIDDLE_H


#include <functional>
#include "Game.h"

//Class for the riddle type games
class Riddle : public Game {

    private:
    int riddleID;

    public:
    //Constructor and deconstructor
    Riddle(int id, std::function<bool(Game*)> solverFunc);
    ~Riddle();

    //Getter for riddle ID
    int getRiddleID() const { return riddleID; }

    //Solver function
    std::function<bool(Game*)> isSolved;


};

#endif //FINAL_REPO_LOCAL_RIDDLE_H