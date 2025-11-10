//
// Created by Avery Williams on 10/24/25.
//

#ifndef FINAL_REPO_LOCAL_PALACE_H
#define FINAL_REPO_LOCAL_PALACE_H


#include <iostream>
#include "Inventory.h"
#include "Map.h"
#include "Player.h"

//Class that runs and manages the entire game
class Palace {

    private:
    Player* player;
    Map gameMap;
    Inventory inventory;
    bool running;

    public:
    //Constructor and deconstructor
    Palace();
    ~Palace();

    //Function to run the game
    void run();

    //Function to process inputs for the character such as, movement and interaction
    void processInput(char input);
};

#endif //FINAL_REPO_LOCAL_PALACE_H