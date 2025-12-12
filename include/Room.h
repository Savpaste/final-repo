#ifndef FINAL_REPO_LOCAL_ROOM1_H
#define FINAL_REPO_LOCAL_ROOM1_H

#include "Player.h"
#include "NPC.h"
#include "RiddleNPC.h"
#include "Puzzle.h"
#include "Riddle.h"
#include <vector>

//Class for each individual room in the game
class Room {

    private:
    int roomID;
    int width;
    int height;
    int startX;
    int startY;
    char** grid;
    std::string roomName;
    std::string roomDescription;
    std::vector <Puzzle> puzzles;
    std::vector <Riddle*> riddles;
    std::vector <Character*> characters;
    std::vector <NPC*> npcs;
    std::vector <RiddleNPC*> riddleNPCs;
    Player* player;
    struct Door {
        int row, col;
        int goToRoomID;
        bool locked;
        RiddleNPC* unlockRiddleNPC;
        Door(int c, int r, int nextID, bool isLocked, RiddleNPC* rnpc = nullptr)
        : col(c), row(r), goToRoomID(nextID), locked(isLocked), unlockRiddleNPC(rnpc) {}
    };
    std::vector <Door> doors;

    public:
    //Constructor, deep copy constructor and destructor
    Room (int roomID, std::string roomName, std::string roomDescription, int width, int height, Player* player);
    Room (const Room& other);
    ~Room();

    //Assignment operator
    Room& operator = (const Room& other);

    //Sets start position for player
    void setStartPosition(int startX, int startY);

    //Getters for room features
    int getRoomID() const {return roomID;}
    std::string getRoomName() const {return roomName;}
    std::string getRoomDescription() const {return roomDescription;}
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getDoorDest(int c, int r);
    int getStartX() const { return startX; }
    int getStartY() const { return startY; }
    std::vector<NPC*> getNPCs() { return npcs; }
    std::vector<RiddleNPC*> getRiddleNPCs() { return riddleNPCs; }
    std::vector<Door>& getDoors() { return doors; }

    //Room actions
    void draw() const;
    bool isWall(int c, int r);
    void addDoor(int c, int r, int nextRoomID, bool locked = false, RiddleNPC* rnpc = nullptr);
    bool unlockDoor(int c, int r);


    //Adds NPCs, RiddleNPCs or games to room
    void addRiddleNPC(RiddleNPC* riddleNPC, int c, int r);
    void addNPC(NPC* npc, int c, int r);
    void addPuzzle(Puzzle puzzle);
    void addRiddle(Riddle* riddle);

    //Player interactions with room
    void leaveRoom();


};

#endif //FINAL_REPO_LOCAL_ROOM1_H