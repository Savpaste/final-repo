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

    void interact(Player* player);

    char getSymbol() { return symbol; }

};

#endif //FINAL_REPO_LOCAL_RIDDLENPC_H