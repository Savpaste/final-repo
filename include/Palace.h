#ifndef FINAL_REPO_LOCAL_PALACE_H
#define FINAL_REPO_LOCAL_PALACE_H


#include "Player.h"
#include "Map.h"
#include "Inventory.h"



//Class that runs and manages the entire game
class Palace {

private:
    Player player;
    Map gameMap;
    Inventory inventory;
    bool running;

    //Function to process inputs for the character such as, movement and interaction
    void processInput(char input);


public:
    //Constructor and deconstructor
    Palace();
    ~Palace();

    Player& getPlayer() {
        return player;
    }

    Room* getCurrentRoom() { return gameMap.getRooms()[gameMap.getCurrentRoomID()];
    }

    //Function to run the game
    void run();

};


#endif //FINAL_REPO_LOCAL_PALACE_H