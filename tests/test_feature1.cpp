#include "../include/Room.h"
#include "../include/Player.h"
#include "../include/NPC.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>


void testNormalOperation();
void testBoundaryConditions();
void testEdgeCase();
// ----------------------------------------------------

// --- HELPER FUNCTION: To Capture Output ---
std::string captureDrawOutput(const Room& room) {
    std::streambuf* old_cout_buf = std::cout.rdbuf();
    std::ostringstream strStream;

    std::cout.rdbuf(strStream.rdbuf());

    room.draw();

    std::cout.rdbuf(old_cout_buf);

    return strStream.str();
}

// Test 1: Normal Operation (Adding Player & NPC)
void testNormalOperation() {
    std::cout << "Test 1: Normal Operation (Adding Player & NPC)...";

    // Setup: 6x6 room. Player position is set by Room constructor at (1, 1).
    Player p("TestHero");
    Room room(1, "TestRoom", "A square room", 6, 6, &p);

    // Create NPC (requires manual cleanup later)
    std::vector<std::string> dialogue = {"Hi"};
    NPC* npc1 = new NPC("Guard", dialogue, 'G');

    // Action: Add NPC to (3, 3)
    room.addNPC(npc1, 3, 3);

    // Assertion 1: Check Player initial position
    assert(p.getX() == 1);

    // Assertion 2: Check NPC state
    assert(room.getNPCs().size() == 1);
    assert(room.getNPCs()[0]->getX() == 3);

    delete npc1; // Cleanup

    std::cout << " PASSED\n";
}

// Test 2: Boundary Conditions (Map Drawing Verification)
void testBoundaryConditions() {
    std::cout << "Test 2: Boundary Conditions (Draw Output)...";

    // Setup: 4x4 room
    Player p("Tester");
    Room room(2, "DrawTest", "4x4", 4, 4, &p);

    // Add NPC at (2, 1)
    std::vector<std::string> dialogue = {"?"};
    NPC* npc2 = new NPC("Riddler", dialogue, '?');
    room.addNPC(npc2, 2, 1);

    // Action: Capture the drawn output
    std::string output = captureDrawOutput(room);

    // Assert 1: Player (@) at Row 1, Col 1. (Index 6 in a 4x4 grid)
    assert(output[6] == '@');

    // Assert 2: NPC (?) at Row 1, Col 2. (Index 7)
    assert(output[7] == '?');

    delete npc2; // Cleanup

    std::cout << " PASSED\n";
}

// Test 3: Edge Case (Movement and Draw)
void testEdgeCase() {
    std::cout << "Test 3: Edge Case (Movement and Draw)...";

    // Setup: Create a 5x5 room
    Player p("Tester");
    Room room(3, "MoveTest", "5x5", 5, 5, &p);

    // Action: Move the player to (3, 3)
    p.setPosition(3, 3);

    // Assertion 1: Check the new position state
    assert(p.getX() == 3);

    // Action 2: Capture output after move
    std::string output = captureDrawOutput(room);

    // Assertion 2: Verify the player symbol '@' appears at the new location (Index 21)
    assert(output[21] == '@');

    std::cout << " PASSED\n";
}


int main() {
    std::cout << "\n=== Running Initial Puzzle Palace Tests ===\n\n";

    try {
        testNormalOperation();
        testBoundaryConditions();
        testEdgeCase();

        std::cout << "\n✅ All initial tests passed!\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\n❌ Test failed with exception: " << e.what() << "\n";
        return 1;
    }
}