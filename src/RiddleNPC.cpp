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

RiddleNPC::~RiddleNPC() {
     delete riddle;
}


void RiddleNPC::interact(Player* player) {
     //Riddle logic to check if riddle is solved and ask the riddle if not
     if (!solvedAlready) {
          solvedAlready = true;
          //riddle->ask();
     } else {
          //Outputs if the riddle has been solved
          cout << "You've already solved this riddle!\n";
          //cin.get();
     }
}