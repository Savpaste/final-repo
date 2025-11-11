//
// Created by Avery Williams on 10/24/25.
//

#ifndef FINAL_REPO_LOCAL_PLAYER_H
#define FINAL_REPO_LOCAL_PLAYER_H


#include <string>
#include "Character.h"
#include "Items.h"
#include "NPC.h"

//Class for the player/user
class Player : public Character {

    private:
    Inventory inventory;

    public:
    //Constructor and deconstructor
    Player(const std::string& name);
    ~Player();

    //Operator overload that allows the player to add items to their inventory
    Player& operator += (const Item& item);

    //Displays inventory
    void showInventory() const;

    //Interact with NPC or not
    bool interact(const NPC& npc, const Item& item, std::string getGameType) const;

};

#endif //FINAL_REPO_LOCAL_PLAYER_H