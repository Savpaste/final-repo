#ifndef FINAL_REPO_LOCAL_RIDDLE_H
#define FINAL_REPO_LOCAL_RIDDLE_H


#include <functional>
#include "Game.h"

//Class for the riddle type games
class Riddle : public Game {

    private:
    int riddleID;
    std::string question;
    std::function<bool(std::string&)> solver;

    public:
    //Constructor and deconstructor
    Riddle(int id, const std::string question, std::function<bool(std::string&)> solverFunc);
    ~Riddle();

    //Getter for riddle ID
    int getRiddleID() const { return riddleID; }

    //Function for NPCs to ask questions
    bool ask();

    //const std::string getRidd() const { return ridd; }

    //Solver function
    //bool riddleSolved(Game* game) {return isSolved(game);}


};

#endif //FINAL_REPO_LOCAL_RIDDLE_H