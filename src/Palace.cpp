#include "Palace.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
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
    //Item torch("Torch", 5);
    //player += torch;

    //Creates a room
    Room* room1 = new Room(1, "Foyer", "a long hallway adorned with paintings and sconces", 12, 8, &player);
    Room* room2 = new Room(2, "Great Hall", "a large, magnificently appointed room used for festivities and gatherings", 18, 8, &player);
    Room* room3 = new Room(3, "Throne Room", "an opulent room with a throne for the King of Puzzle Palace", 12, 8, &player);
    Room* room4 = new Room(4, "Dungeon", "a dank stone chamber with skeletons strewn about", 8, 8, &player);
    Room* room5 = new Room(5, "Vault", "a Room filled with treasure chests and various riches", 14, 16, &player);
    Room* room6 = new Room(6, "The Chamber of the Gods", "Sweet, sweet freedom and conquest!", 5, 5, &player);

    //Adds dialogue for NPCs to a vector
    vector<string> servantDialogue = {
        "Welcome to the Puzzle Palace, traveler. Make your way through by solving riddles.",
        "There's riches to be had ahead!"
    };
    vector<string> butlerDialogue = {
        "Hello, traveler. Eat, drink and be merry.",
        "Take a seat... you may be here a while."
    };
    vector<string> soldierDialogue = {
        "Bow to your king, or be thrown in the dungeon!",
        "Be gone, you peasant!"
    };
    vector<string> ghostDialogue = {
        "I am a lost soul. Pray you do not meet the same fate.",
        "BOOOOOOOOOO!!!"
    };
    vector<string> guardDialogue = {
        "Behold.. Riches beyond belief!",
        "Take your fill, adventurer... You've earned it."
    };

    //Creates NPC and attributes
    NPC* servant = new NPC ("Archibald", servantDialogue, 'a');
    NPC* butler = new NPC("Jeeves", butlerDialogue, 'j');
    NPC* soldier = new NPC ("Roland", soldierDialogue, 'r');
    NPC* ghost = new NPC ("Booderick", ghostDialogue, 'g');
    NPC* guard = new NPC ("William", guardDialogue, 'w');


    //Adds NPC to room
    room1->addNPC(servant, 3, 1);
    room2->addNPC(butler, 6, 4);
    room3->addNPC(soldier, 3, 2);
    room4->addNPC(ghost, 2, 3);
    room5->addNPC(guard, 4, 4);

    //Creates riddle and answer
    Riddle* riddle1 = new Riddle(1, "What is the beginning of eternity, the end of time and space, and the end of life as we know it?", []( const string& answer) { return answer == "E" || answer == "e"; });
    Riddle* riddle2 = new Riddle(2, "What word in the dictionary is spelled incorrectly?", []( const string& answer) { return answer == "Incorrectly" || answer == "incorrectly"; });
    Riddle* riddle3 = new Riddle(3,"What can you put in a bucket to make it weigh less?", []( const string& answer) { return answer == "A hole" || answer == "a hole"; });
    Riddle* riddle4 = new Riddle(3,"I am a solitary word, 5 letters long. Behead me once, I am the same. Behead me again, I am still the same.", []( const string& answer) { return answer == "Alone" || answer == "alone"; });
    Riddle* riddle5 = new Riddle(3,"What is one thing that all wise men, regardless of their politics or religion, have to agree is between heaven and earth??", []( const string& answer) { return answer == "And" || answer == "and"; });


    //Creates RiddleNPC and attributes including the riddle to be asked
    RiddleNPC* steward = new RiddleNPC("Stewie", riddle2, 'S');
    RiddleNPC* knight = new RiddleNPC("Lancelot", riddle3, 'L');
    RiddleNPC* king =  new RiddleNPC("King Avery", riddle5, 'K');
    RiddleNPC* executioner = new RiddleNPC("Griff", riddle4, 'G');
    RiddleNPC* treasurer = new RiddleNPC("Treasurer", riddle1, 'T');

    //Adds RiddleNPC to room
    room1->addRiddleNPC(steward, 5, 3);
    room2->addRiddleNPC(knight, 10, 5);
    room3->addRiddleNPC(king, 5, 4);
    room4->addRiddleNPC(executioner, 6, 6);
    room5->addRiddleNPC(treasurer, 4, 12);

    //Adds door location and destination ID to next room,  and adds the start position for the player for the next room
    room1->addDoor(4,5,2, true, steward);
    room1->setStartPosition(1,1);
    room2->addDoor(12, 6, 3, true, knight);
    room2->setStartPosition(1,1);
    room3->addDoor(7,6, 4, true, king);
    room3->setStartPosition(1,1);
    room4->addDoor(4, 4, 5, true, executioner);
    room4->setStartPosition(1,1);
    room5->addDoor(3, 14, 6, true, treasurer);
    room5->setStartPosition(1,1);

    //Adds room to overall map
    gameMap.addRoom(room1);
    gameMap.addRoom(room2);
    gameMap.addRoom(room3);
    gameMap.addRoom(room4);
    gameMap.addRoom(room5);
    gameMap.addRoom(room6);

    cout << "Puzzle Palace built\n";
    cout << endl;
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

    //Checks for door at player's position and gets destination for that door
    int nextRoomID = currentRoom->getDoorDest(newX, newY);
    if (nextRoomID != -1) {
        //Room change logic
        cout << "You step through the door...\n";
        currentRoom->leaveRoom();
        gameMap.changeRoom(nextRoomID);
        Room* newRoom = gameMap.getCurrentRoom();
        if (newRoom) {
            player.setPosition(newRoom->getStartX(), newRoom->getStartY());
            cout << "You are now entering the " << newRoom->getRoomName() << endl;
            cout << "It is " << newRoom->getRoomDescription() << endl;
        }
        return;
    } else {
        //Door still locked
        bool blockedByDoor = false;
        for (auto& door : currentRoom->getDoors()) {
            if (door.row == newY && door.col == newX && door.locked) {
                if (door.locked) {
                    blockedByDoor = true;
                }
                break;
            }
        }
        if (blockedByDoor) return;
    }

    //Safe to move
    player.setPosition(newX, newY);
}

//ChatGPT wrote this to clear the screen in terminal and use newline in CLion. Newline function not working
void clearScreen() {
    // If output is a terminal, use ANSI codes
    if (isatty(STDOUT_FILENO)) {
        std::cout << "\033[2J\033[H"; // clear screen and move cursor to home
    } else {
        // Otherwise, print 30 newlines to simulate clearing
        for (int i = 0; i < 30; ++i) {
            std::cout << "\n";
        }
    }
    std::cout.flush(); // make sure output is sent immediately
}


void Palace::run() {

    while (running) {

        clearScreen();
        //system("clear");

        cout << endl;
        cout << "=== Puzzle Palace ===\n";
        cout << endl;
        gameMap.drawCurrentRoom();
        cout << endl;


        cout << "Enter W/A/S/D to move or Q to quit (press enter after): ";
        char input;
        cin >> input;
        cout << endl;

        processInput(input);

        //Game end logic
        Room* current = gameMap.getCurrentRoom();
        if (current->getRoomName() == "The Chamber of the Gods") {
            cout << "\nAs you step into the final chamber... A warm light surrounds you and you realize you're a boss!!" << endl;
            cout << "*** CONGRATULATIONS " << player.getName() << ", YOU HAVE ESCAPED PUZZLE PALACE WITH RICHES AND REPUTE! ***" << endl;

            running = false;
            return;
        }

    }
}