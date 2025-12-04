#include "Palace.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

static std::string inputName() {
    cout << "Enter your character's name: ";
    string name;
    getline(cin, name);
    cout << endl;

    if (name.empty()) name = "Hero";
    return name;
}

Palace::Palace()
    : player(inputName()),
    inventory(10),
    running(true) {

    //Creates an item and adds it to the players inventory
    Item torch("Torch", 5);
    player += torch;

    //Creates a room
    Room* room1 = new Room(1, "Foyer", "Entryway", 15, 15, &player);
    Room* room2 = new Room(2, "Dungeon", "Torture Chamber", 15, 15, &player);

    //Adds dialogue for NPCs to a vector
    vector<string> butlerDialogue = {
        "Welcome to the Puzzle Palace, traveler",
        "There's riches to be had ahead"
        };

    //Creates NPC and attributes
    NPC* butler = new NPC("Butler", butlerDialogue, 'b');
    //Adds NPC to room
    room1->addNPC(butler, 5, 3);

    //Creates riddle and answer
    Riddle* riddle1 = new Riddle(1, "What is the beginning of eternity, the end of time and space, and the end of life as we know it?", []( const string& answer) { return answer == "E";});

    //Creates RiddleNPC and attributes including the riddle to be asked
    RiddleNPC* ghost = new RiddleNPC("Ghost", riddle1, 'G');
    //Adds RiddleNPC to room
    room1->addRiddleNPC(ghost, 3, 3);

    room1->addDoor(8,8,2);

    //Adds room to overall map
    gameMap.addRoom(room1);
    if (gameMap.getCurrentRoom()) {
        cout << "Current room is set: "
             << gameMap.getCurrentRoom()->getRoomName() << endl;
    } else {
        cout << "Current room is nullptr!" << endl;
    }
    gameMap.addRoom(room2);

    //cout << "Puzzle Palace built.\n";
}

Palace::~Palace() {
    for (Room* room : gameMap.getRooms()) {
        delete room;
    }
}

void Palace::processInput(char input) {
    input = toupper(input); //Allows for lowercase inputs to be valid
    //Updates player location
    int newX = player.getX();
    int newY = player.getY();

    //Allocates input buttons for movement
    switch (input) {
        case 'W': newY--; break;
        case 'S': newY++; break;
        case 'A': newX--; break;
        case 'D': newX++; break;
        case 'Q': running = false;
            return ;
        default:
            cout << "Invalid input\n";
            //Pauses read out for a specified amount of time
            this_thread::sleep_for(chrono::milliseconds(500));
    }

    //Designates which room is drawn
    Room* currentRoom = gameMap.getCurrentRoom();

    //Check walls and returns cout if player runs into wall
    if (currentRoom->isWall(newX, newY)) {
        cout << "OUCH!! You hit a wall!\n";
        cout << endl;
        return;
    }


    //Check NPCs collisions
    for (auto& npc : currentRoom->getNPCs()) {
        if (npc->getX() == newX && npc->getY() == newY) {
            player.interactNPC(npc);  // trigger interaction
            return; // stop moving
        }
    }

    //Check RiddleNPCs collisions
    for (auto& rnpc : currentRoom->getRiddleNPCs()) {
        if (rnpc->getX() == newX && rnpc->getY() == newY) {
            player.interactRiddleNPC(rnpc);
            return;  // stop moving
        }
    }
    int nextRoomID = currentRoom->getDoorDest(newX, newY);
    if (nextRoomID != -1) {
        cout << "You step through the door...\n";

        // Optional: perform room cleanup
        currentRoom->leaveRoom();

        // Change to the new room
        gameMap.changeRoom(nextRoomID);

        // Update player coordinates to the new room's spawn point
        //Room* newRoom = gameMap.getRooms()[nextRoomID];
        //player.setPosition(newRoom->getStartX(), newRoom->getStartY());

        return; // stop further movement in this tick
    }
    //Safe to move
    player.setPosition(newX, newY);
}

void Palace::run() {

    while (running) {

        cout << endl;
        gameMap.drawCurrentRoom();
        cout << endl;

        player.showInventory();
        cout << endl;


        cout << "Enter W/A/S/D to move or Q to quit: ";
        char input;
        cin >> input;
        cout << endl;

        processInput(input);
    }
}