#ifndef FINAL_REPO_LOCAL_PLAYER_H
#define FINAL_REPO_LOCAL_PLAYER_H

#include "Character.h"
#include "Inventory.h"
#include "Items.h"
#include <string>



class NPC;
class RiddleNPC;

//Class for the player/user
class Player : public Character {

    private:
    Inventory inventory;

    public:
    //Constructor and deconstructor
    Player(std::string playerName);
    ~Player();

    //Operator overload that allows the player to add items to their inventory
    Player& operator += (const Item& item);

    //Displays inventory
    void showInventory() const;

    //Interact with NPC/item or not
    bool interactNPC(NPC* npc) const;
    bool interactRiddleNPC(RiddleNPC* riddleNPC);
    bool interactItem(Item* item) const;

};

#endif //FINAL_REPO_LOCAL_PLAYER_H