

#include <iostream>
#include <string>
#include "Palace.h"
#include "Player.h"
#include "NPC.h"
#include "Map.h"
#include "Room.h"
#include "Items.h"
using namespace std;


//Calls the operator overloader for adding items and returns the item name and value
ostream& operator<<(ostream& out, const Item& item) {
    out << "[" << item.name << "]" << " (Value: " << item.value << ")";
    return out;
}

//TODO: Setup opening menu
void displayMenu() {
    cout << "--- Puzzle Palace Main Menu ---\n";
    cout << "1. Play\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n";
    cout << "Please enter your choice: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > 3) {
        cout << "Invalid choice. Please choose again\n";
    }

    //TODO: Execute choice
}





int main() {
    cout << "=== Welcome to the Puzzle Palace ===" << endl;

    //TODO: Create the player
    string playerName;
    cout << "Please enter your name: ";
    cin >> playerName;
    Player player(playerName);

    //TODO: Create NPCs
    NPC x("Butler");
    x.setDialogue("Welcome to the Foyer.  The game is... What is your answer?\n");
    NPC y("Ghost");
    NPC z("Inmate");

    //TODO create games
    Puzzle puzzle1(1, [](Game* game) {
    std::string answer1;
    cout << "What is xyz? ";
    cin >> answer1;
    return answer1 == "abc";
});
    Riddle riddle1(1, [](Game* game) {return false;});

    //TODO: Create the map and rooms
    Map map;
    Room room1(1, "Foyer", "Entryway", 8, 8, &player);
    Room room2(2, "Great Hall", "Main Room", 15, 15, &player);
    Room room3(3, "Torture Chamber", "A dank underground dungeon", 10, 10, &player);

    //TODO: Add NPCs and games to rooms
    room1.addNPC(x);
    room1.addPuzzle(puzzle1);
    room1.addRiddle(riddle1);

    //TODO: Add rooms to map
    map.addRoom (room1);
    map.addRoom (room2);
    map.addRoom (room3);


    //TODO: Start game and display main menu
    displayMenu();
    cout << "You are now entering Puzzle Palace\n";

    //TODO: Run "Palace"
    Palace palace;
    palace.run();

    //TODO: End game
    cout << "Thank you for playing Puzzle Palace!\n";

return 0;
}