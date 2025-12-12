#include "Riddle.h"

#include <iostream>
using namespace std;


Riddle::Riddle(int id, const string q, function<bool(string&)> solverFunc)
    : riddleID(id),
    question(q),
    solver(solverFunc) {
    gameType = "Riddle";

}

bool Riddle::ask() {

    //Clears the buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //Logic to ask the riddle
    while (true) {

        //Question and input for guess
        cout << question << "\n> ";
        string answer;
        getline(cin, answer);

        //If solved returns true.  If not returns false.
        if (solver(answer)) {
            solved = true;
            cout << endl;
            cout << "Correct! The door is now unlocked!\n";
            return true;
        }

        //Validation logic. Reenter guess if wrong
        cout << endl;
        cout << "Incorrect! Please try again!\n";
        cout << endl;
    }
}
