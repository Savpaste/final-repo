#include "Palace.h"
#include <iostream>
using namespace std;

//Displays the instructions
void displayInstructions() {

    cout << endl << endl;
    cout << "--- INSTRUCTIONS ---\n";
    cout << endl;
    cout << "You must traverse the palace and answer riddles. \n"
            "Characters are represented by single letters. \n"
            "The lower case letters represent NPCs that only have dialogue, and the upper case letters represent NPCs that will ask a riddle. \n"
            "Solve all the games to escape the palace. Good luck, adventurer!!\n";
    cout << endl;

    cout << "Enter W to move up\n";
    cout << "Enter S to move down\n";
    cout << "Enter A to move left\n";
    cout << "Enter D to move right\n";
    cout << "Enter Q to quit\n";
    cout << endl;
}

//Displays the opening menu
void displayMenu() {
    int choice;

    do {
        cout << "--- PUZZLE PALACE MAIN MENU ---\n";
        cout << endl;
        cout << "1. Play\n";
        cout << "2. Instructions\n";
        cout  << endl;
        cout << "Please enter your choice: ";

        if (!(cin >> choice)) {

            cout << endl;
            cout << "Invalid input. Please enter a number!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            choice = 0;

        } else if (choice == 1) {
            break;

        } else if (choice == 2) {
            displayInstructions();
            break;

        } else {
            cout << endl;
            cout << "Invalid choice. Please choose again! \n";
            cout << endl;
        }
    } while (true);
}


int main() {


    cout << endl;
    cout << "=== WELCOME TO PUZZLE PALACE ===" << endl;
    cout << endl;

    displayMenu();
    cin.ignore();
    cout << endl;

    Palace palace;

    cout << "Press enter to start game... ";
    cin.ignore();
    cout << endl;

    system("clear");

    palace.run();

    cout << "Thank you for playing Puzzle Palace!\n";
    cout << endl;

return 0;
}