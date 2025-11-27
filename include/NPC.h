#ifndef FINAL_REPO_LOCAL_NPC_H
#define FINAL_REPO_LOCAL_NPC_H

#include "Character.h"
#include "Player.h"
#include "Riddle.h"
#include <vector>
#include <string>

//Class for all the non player characters
class NPC : public Character {

    protected:
    char symbol;
    std::vector<std::string> dialogue;
    int dialogueIndex;

    public:
    //Constructor and deconstructor
    NPC(std::string name, std::vector<std::string> dialogueLines, char symbol);
    ~NPC();

    //void interact(Player* player);

    //Dialogue implementation
    void speak();
    void addDialogue(std::string line);
    //void setRiddle(Riddle* r);

    //void interact();

    //Getter for the NPCs representative character/symbol
    char getSymbol() const { return symbol; }

};

#endif //FINAL_REPO_LOCAL_NPC_H