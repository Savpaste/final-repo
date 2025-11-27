#include "Player.h"
#include "NPC.h"
#include "RiddleNPC.h"
#include "Items.h"
#include <iostream>
using namespace std;

Player::Player(string name) : Character(name),
    inventory(10) {

    cout << "Player " << name << " has entered the Palace" << endl;
    cout << endl;
}

Player::~Player() {

    cout << "Player " << name << " has left the palace" << endl;
}

Player& Player::operator += (const Item& item) {
    inventory.addItem(item);
    return *this;
}

void Player::showInventory() const {
    cout << name << "'s inventory ";
    inventory.display();
}


bool Player::interactNPC(NPC* npc) const {
    npc->speak();
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    return true;
}

bool Player::interactRiddleNPC(RiddleNPC* rnpc) {
    rnpc->interact(this);
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    return true;
}


