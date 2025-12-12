#include "Character.h"
using namespace std;

Character::Character(string name) :
    name (name),
    x(0), y(0) {

    cout << "Character " << name << " created" << endl;
    cout << endl;
}

Character::~Character() {

    //cout << "Character " << name << " destroyed." << endl;
    //cout << endl;
}

void Character::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}
