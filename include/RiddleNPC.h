#ifndef FINAL_REPO_LOCAL_RIDDLENPC_H
#define FINAL_REPO_LOCAL_RIDDLENPC_H

#include "Character.h"
#include "Player.h"
#include "Riddle.h"

class Player;

class RiddleNPC : public Character {

    private:
    char symbol;
    Riddle* riddle;
    bool solvedAlready;

    public:
    //Constructor and deconstructor
    RiddleNPC(std::string name, Riddle* r, char symbol);
    ~RiddleNPC();

    //Function for the player to interact with the RiddleNPCs
    void interact(Player* player);

    //Returns the symbol that represents the RiddleNPC
    char getSymbol() { return symbol; }
    Riddle* getRiddle() { return riddle; }

    bool isSolved() const { return solvedAlready; }

};

#endif //FINAL_REPO_LOCAL_RIDDLENPC_H