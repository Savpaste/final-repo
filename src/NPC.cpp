#include "NPC.h"
#include "Player.h"
using namespace std;


NPC::NPC(string name, vector<string> dialogueLines, char symbol) : Character(name),
    dialogue(dialogueLines),
    dialogueIndex(0),
    symbol(symbol)
    //riddle(nullptr)
{}

NPC::~NPC() {

    cout << "NPC destroyed" << endl;
}

//void NPC::setRiddle(Riddle* r) { riddle = r; }

void NPC::addDialogue(std::string line) {
    dialogue.push_back(line);
}

/*void NPC::interact(Player* player) {
    for (auto& line : dialogue) {
        cout << name << " says: " << line << endl;
    }
    if (riddle) {
        riddle->ask();
    }
}*/

void NPC::speak() {
    if (!dialogue.empty() && dialogueIndex < dialogue.size()) {
        cout << name << " says: \"" << dialogue[dialogueIndex] << "\"" << endl;
        dialogueIndex++;
    } else {
        cout << name << " has nothing to say" << endl;}
}


