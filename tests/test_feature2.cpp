#include "../include/Palace.h"
#include "../include/RiddleNPC.h"
#include "../include/Player.h"
#include "../include/Room.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <exception>

// ---------- Stream Helpers ----------
void redirectStreams(std::istringstream& inputSS,
                     std::streambuf*& oldCin,
                     std::streambuf*& oldCout) {
    oldCin = std::cin.rdbuf();
    oldCout = std::cout.rdbuf();

    static std::ostringstream outputSink;
    std::cin.rdbuf(inputSS.rdbuf());
    std::cout.rdbuf(outputSink.rdbuf());
}

void restoreStreams(std::streambuf* oldCin,
                    std::streambuf* oldCout) {
    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);
}

// ------------------------------------
void testRiddle_InitialSolve() {
    std::cout << "Test 1: Normal Operation (Riddle Solve)...";

    std::string testInput = "P\nI\nE\n";
    std::istringstream inputSS(testInput);

    std::streambuf* oldCin;
    std::streambuf* oldCout;
    redirectStreams(inputSS, oldCin, oldCout);

    {
        Palace game;
        Room* room = game.getCurrentRoom();
        auto riddleNPCs = room->getRiddleNPCs();
        assert(!riddleNPCs.empty());
        RiddleNPC* ghost = riddleNPCs[0];

        ghost->interact(&game.getPlayer());
        assert(ghost->isSolved());
    }

    restoreStreams(oldCin, oldCout);
    std::cout << " PASSED\n";
}

// ------------------------------------
void testRiddle_ReInteractionBlock() {
    std::cout << "Test 2: Edge Case (Re-Interaction Block)...";

    std::string testInput = "H\nE\nQ\n";
    std::istringstream inputSS(testInput);

    std::streambuf* oldCin;
    std::streambuf* oldCout;
    redirectStreams(inputSS, oldCin, oldCout);

    {
        Palace game;
        Room* room = game.getCurrentRoom();
        auto riddleNPCs = room->getRiddleNPCs();
        assert(!riddleNPCs.empty());
        RiddleNPC* ghost = riddleNPCs[0];

        ghost->interact(&game.getPlayer());
        assert(ghost->isSolved());

        // Second interaction
        ghost->interact(&game.getPlayer());
        assert(ghost->isSolved());
    }

    restoreStreams(oldCin, oldCout);
    std::cout << " PASSED\n";
}

// ------------------------------------
void testRiddle_IncorrectLoop() {
    std::cout << "Test 3: Boundary Condition (Multiple Fails)...";

    std::string testInput = "N\nX\nY\nZ\nE\n";
    std::istringstream inputSS(testInput);

    std::streambuf* oldCin;
    std::streambuf* oldCout;
    redirectStreams(inputSS, oldCin, oldCout);

    {
        Palace game;
        Room* room = game.getCurrentRoom();
        auto riddleNPCs = room->getRiddleNPCs();
        assert(!riddleNPCs.empty());
        RiddleNPC* ghost = riddleNPCs[0];

        ghost->interact(&game.getPlayer());
        assert(ghost->isSolved());
    }

    restoreStreams(oldCin, oldCout);
    std::cout << " PASSED\n";
}

// ------------------------------------
int main() {
    std::cout << "\n=== Running Tests for Riddle Logic Feature ===\n\n";

    try {
        testRiddle_InitialSolve();
        testRiddle_ReInteractionBlock();
        testRiddle_IncorrectLoop();

        std::cout << "\nAll tests passed!\n";
        return 0;
    } catch (...) {
        std::cerr << "\n❌ Test failed (unexpected exception)\n";
        return 1;
    }
}
