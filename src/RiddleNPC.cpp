#include "RiddleNPC.h"
#include "Player.h"
#include <iostream>
#include <string>
using namespace std;

RiddleNPC::RiddleNPC(string name, Riddle* r, char symbol) : Character(name),
     riddle(r),
     symbol(symbol),
     solvedAlready(false){
}

RiddleNPC::~RiddleNPC() {}


void RiddleNPC::interact(Player* player) {
     if (!solvedAlready) {
          solvedAlready = true;
          riddle->ask();
     } else {
          cout << "You've already tried\n";
     }
};