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

bool Riddle::ask() {

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (true) {

        cout << question << "\n> ";
        string answer;
        getline(cin, answer);

        if (solver(answer)) {
            cout << endl;
            cout << "Correct!\n";
            return true;
        }

        cout << endl;
        cout << "Incorrect! Please try again!\n";
        cout << endl;
    }
}
