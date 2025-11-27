#include "../include/Room.h"
#include "../include/Player.h"
#include "../include/NPC.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

std::string captureDrawOutput(const Room& room) {
    std::streambuf* old_cout_buf = std::cout.rdbuf();
    std::ostringstream strStream;

    std::cout.rdbuf(strStream.rdbuf());

    room.draw();

    std::cout.rdbuf(old_cout_buf);

    return strStream.str();
}

void testNormalOperation() {
    std::cout << "Test 1: Normal Operation (Adding Player & NPC)...";

    Player p("TestHero");
    Room room(1, "TestRoom", "A square room", 6, 6, &p);

    std::vector<std::string> dialogue = {"Hi"};
    NPC* npc1 = new NPC("Guard", dialogue, 'G');

    room.addNPC(npc1, 3, 3);

    assert(p.getX() == 1);
    assert(p.getY() == 1);

    assert(room.getNPCs().size() == 1);
    assert(room.getNPCs()[0]->getX() == 3);
    assert(room.getNPCs()[0]->getY() == 3);

    delete npc1;

    std::cout << " PASSED\n";
}

void testBoundaryConditions() {
    std::cout << "Test 2: Boundary Conditions (Draw Output)...";

    Player p("Tester");
    Room room(2, "DrawTest", "4x4", 4, 4, &p);

    std::vector<std::string> dialogue = {"?"};
    NPC* npc2 = new NPC("Butler", dialogue, 'B');
    room.addNPC(npc2, 2, 1);

    std::string output = captureDrawOutput(room);

    assert(output[6] == '@');

    assert(output[7] == 'B');

    assert(output[16] == '#');

    delete npc2;

    std::cout << " PASSED\n";
}

void testEdgeCase() {
    std::cout << "Test 3: Edge Case (Movement and Draw)...";

    Player p("Tester");
    Room room(3, "MoveTest", "5x5", 5, 5, &p);

    assert(p.getX() == 1);

    p.setPosition(3, 3);

    assert(p.getX() == 3);
    assert(room.isWall(3, 3) == false);

    std::string output = captureDrawOutput(room);

    assert(output[21] == '@');

    std::cout << " PASSED\n";
}


int main() {
    std::cout << "\n=== Running Tests for Puzzle Palace Room Feature ===\n\n";

    try {
        testNormalOperation();
        testBoundaryConditions();
        testEdgeCase();

        std::cout << "\n✅ All tests passed!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n❌ Test failed with exception: " << e.what() << "\n";
        return 1;
    }
}