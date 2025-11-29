#include "Palace.h"
#include "Items.h"
#include <iostream>
#include <string>
using namespace std;




void displayInstructions() {

    cout << endl << endl;
    cout << "--- Instructions ---\n";
    cout << endl;
    cout << "You must traverse the palace and answer riddles and complete puzzles to advance. \n"
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


//TODO: Setup opening menu
void displayMenu() {
    int choice;

    do {
        cout << "--- Puzzle Palace Main Menu ---\n";
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
    cout << "=== Welcome to the Puzzle Palace ===" << endl;
    cout << endl;

    displayMenu();
    cin.ignore();
    cout << endl;

    Palace palace;

    cout << "Press enter to start game... ";
    cin.ignore();
    cout << endl;

    palace.run();



    /*//TODO create games
    Puzzle puzzle1(1, [](Game* game) {
    std::string answer1;
    cout << "What is xyz? ";
    cin >> answer1;
    return answer1 == "abc";
});
    Riddle riddle1(1, [](Game* game) {return false;});

    //TODO: Create the map and rooms
    Map map;
    Room room1(1, "Foyer", "Entryway", 8, 8, &player);
    Room room2(2, "Great Hall", "Main Room", 15, 15, &player);
    Room room3(3, "Torture Chamber", "A dank underground dungeon", 10, 10, &player);

    //TODO: Add NPCs and games to rooms
    //room1.addNPC();
    room1.addPuzzle(puzzle1);
    room1.addRiddle(riddle1);




    //TODO: End game
    cout << "Thank you for playing Puzzle Palace!\n";
*/

return 0;
}