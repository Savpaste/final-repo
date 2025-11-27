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


    Item torch("Torch", 5);
    player += torch;

    Room* room1 = new Room(1, "Foyer", "Entryway", 15, 15, &player);


    vector<string> butlerDialogue = {
        "Welcome to the Puzzle Palace, traveler",
        "There's riches to be had ahead"
        };

    /*NPC* butler = new NPC("Butler", butlerDialogue, 'b');
    room1->addNPC(butler, 5, 3);

    Riddle* riddle1 = new Riddle(1, "What is the beginning of eternity, the end of time and space, and the end of life as we know it?", []( const string& answer) { return answer == "E";});

    RiddleNPC* ghost = new RiddleNPC("Ghost", riddle1, 'G');
    room1->addRiddleNPC(ghost, 3, 3);

    gameMap.addRoom(room1);*/


    //cout << "Puzzle Palace built.\n";
}

Palace::~Palace() {

    cout << "Puzzle Palace destroyed.\n";
}


void Palace::processInput(char input) {
    input = toupper(input);
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

    Room* currentRoom = gameMap.getRooms()[gameMap.getCurrentRoomID()];

    // Check walls
    if (currentRoom->isWall(newX, newY)) {
        cout << "OUCH!! You hit a wall!\n";
        cout << endl;
        return;
    }


    // Check NPC collisions
    for (auto& npc : currentRoom->getNPCs()) {
        if (npc->getX() == newX && npc->getY() == newY) {
            player.interactNPC(npc);  // trigger interaction
            return; // stop moving
        }
    }

    // Check RiddleNPCs collisions
    for (auto& rnpc : currentRoom->getRiddleNPCs()) {
        if (rnpc->getX() == newX && rnpc->getY() == newY) {
            player.interactRiddleNPC(rnpc);
            return;  // stop moving
        }
    }

    // Safe to move
    player.setPosition(newX, newY);
}

void Palace::run() {

    while (running) {

        system("clear");
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