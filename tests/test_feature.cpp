#include "../include/Palace.h"
#include "../include/RiddleNPC.h"
#include "../include/Player.h"
#include "../include/Room.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

// Helper to simulate input and capture output
class StreamRedirector {
public:
    StreamRedirector(const std::string& input) {
        oldCin = std::cin.rdbuf(inputSS.rdbuf());
        oldCout = std::cout.rdbuf(outputSS.rdbuf());
        inputSS.str(input);
    }
    ~StreamRedirector() {
        std::cin.rdbuf(oldCin);
        std::cout.rdbuf(oldCout);
    }
    std::string getOutput() const { return outputSS.str(); }

private:
    std::istringstream inputSS;
    std::ostringstream outputSS;
    std::streambuf* oldCin;
    std::streambuf* oldCout;
};

// ----------------- Test Cases -----------------

// 1. Normal operation: solving the riddle
void testRiddle_Normal() {
    StreamRedirector sr("P\nI\nE\n"); // Example correct inputs

    Palace game;
    Room* room = game.getCurrentRoom();
    auto riddleNPCs = room->getRiddleNPCs();
    assert(!riddleNPCs.empty());

    RiddleNPC* npc = riddleNPCs[0];
    npc->interact(&game.getPlayer());

    assert(npc->isSolved()); // Should be solved
    std::cout << "Test Normal Operation PASSED\n";
}

// 2. Edge case: interacting again after riddle is solved
void testRiddle_EdgeCase() {
    StreamRedirector sr("H\nE\nQ\n"); // Inputs for first interaction

    Palace game;
    Room* room = game.getCurrentRoom();
    auto riddleNPCs = room->getRiddleNPCs();
    RiddleNPC* npc = riddleNPCs[0];

    npc->interact(&game.getPlayer());  // Solve riddle
    assert(npc->isSolved());

    // Second interaction should not break anything
    npc->interact(&game.getPlayer());
    assert(npc->isSolved());  // Still solved
    std::cout << "Test Edge Case PASSED\n";
}

// 3. Boundary / integration: multiple wrong answers then correct
void testRiddle_Boundary() {
    StreamRedirector sr("N\nX\nY\nZ\nE\n"); // Several wrong then correct

    Palace game;
    Room* room = game.getCurrentRoom();
    auto riddleNPCs = room->getRiddleNPCs();
    RiddleNPC* npc = riddleNPCs[0];

    npc->interact(&game.getPlayer());  // Interact with riddle
    assert(npc->isSolved());            // Finally solved
    std::cout << "Test Boundary/Integration PASSED\n";
}

// ----------------- Main -----------------
int main() {
    std::cout << "\n=== Running Riddle Feature Tests ===\n";

    testRiddle_Normal();
    testRiddle_EdgeCase();
    testRiddle_Boundary();

    std::cout << "\nAll tests PASSED!\n";
    return 0;
}
