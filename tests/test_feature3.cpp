#include <iostream>
#include <cassert>
#include "Room.h"
#include "Map.h"
#include "Player.h"

using namespace std;

static void printTestHeader(const string& name) {
    cout << "\n=== Running Test: " << name << " ===\n";
}

int main() {

    cout << "\n=== Running Room Transition Feature Tests ===\n" << endl;

    // Create player
    Player player("Tester");
    player.setPosition(1, 1);

    // ---------------------------
    // SETUP: Create rooms
    // ---------------------------

    Room* room1 = new Room(1, "Room1", "First room", 10, 10, &player);
    Room* room2 = new Room(2, "Room2", "Second room", 10, 10, &player);
    Room* room3 = new Room(3, "Room3", "Third room", 10, 10, &player);

    room1->setStartPosition(1, 1);
    room2->setStartPosition(2, 2);
    room3->setStartPosition(3, 3);

    // Add doors
    room1->addDoor(5, 5, 2);   // Room1 → Room2
    room2->addDoor(4, 4, 3);   // Room2 → Room3

    // Add rooms to map
    Map map;
    map.addRoom(room1);
    map.addRoom(room2);
    map.addRoom(room3);

    // --------------------------------------------------------------
    // TEST 1: Normal Operation (player steps on valid door)
    // --------------------------------------------------------------
    printTestHeader("Normal Room Transition");

    int dest1 = room1->getDoorDest(5, 5);
    assert(dest1 == 2);

    map.changeRoom(dest1);
    assert(map.getCurrentRoom()->getRoomID() == 2);

    cout << "PASS: Normal room transition works.\n";

    // --------------------------------------------------------------
    // TEST 2: Edge Case — stepping on tile that is NOT a door
    // --------------------------------------------------------------
    printTestHeader("Non-Door Tile Should Not Change Room");

    int dest2 = room2->getDoorDest(1, 1);  // empty tile -> should return -1
    assert(dest2 == -1);

    // Ensure room didn't change
    assert(map.getCurrentRoom()->getRoomID() == 2);

    cout << "PASS: Non-door tile does not change room.\n";

    // --------------------------------------------------------------
    // TEST 3: Boundary/Integration — chained transitions
    // --------------------------------------------------------------
    printTestHeader("Multi-Room Chain Transition");

    int dest3 = room2->getDoorDest(4, 4);
    assert(dest3 == 3);

    map.changeRoom(dest3);
    assert(map.getCurrentRoom()->getRoomID() == 3);

    cout << "PASS: Multi-step room transition chain works.\n";

    cout << "\nAll tests PASSED!\n";
    return 0;
}
