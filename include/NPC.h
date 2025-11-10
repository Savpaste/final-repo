//
// Created by Avery Williams on 10/24/25.
//

#ifndef FINAL_REPO_LOCAL_NPC_H
#define FINAL_REPO_LOCAL_NPC_H


#include <iostream>
#include "Character.h"

//Class for all the non player characters
class NPC : public Character {

    private:
    char symbol;
    std::string dialogue;

    public:
    //Constructor and deconstructor
    NPC(const std::string& name);
    ~NPC();

    //Getter for the NPCs representative character/symbol
    char getSymbol() const { return symbol; }

    void setDialogue(std::string dialogue) { this->dialogue = dialogue; }
    std::string getDialogue() const { return dialogue; }

};

#endif //FINAL_REPO_LOCAL_NPC_H