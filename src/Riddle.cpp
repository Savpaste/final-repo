#include "Riddle.h"

#include <iostream>
using namespace std;


Riddle::Riddle(int id, const string q, function<bool(string&)> solverFunc)
    : riddleID(id),
    question(q),
    solver(solverFunc) {
    gameType = "Riddle";

}

Riddle::~Riddle() {}

void Riddle::ask() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << question << "\n> ";

    std::string answer;
    std::getline(std::cin, answer);

    if (solver(answer)) {
        std::cout << "Correct!\n";
    } else {
        std::cout << "Incorrect!\n";
    }
}

