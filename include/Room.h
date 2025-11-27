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
    char** grid;
    std::string roomName;
    std::string roomDescription;
    std::vector <Puzzle> puzzles;
    std::vector <Riddle*> riddles;
    std::vector <Character*> characters;
    std::vector <NPC*> npcs;
    std::vector <RiddleNPC*> riddleNPCs;
    Player* player;

    public:
    //Constructor, deep copy constructor and destructor
    Room (int roomID, std::string roomName, std::string roomDescription, int width, int height, Player* player);
    Room (const Room& other);
    ~Room();

    //Assignment operator
    Room& operator = (const Room& other);

    //Getters for room features
    int getRoomID() const {return roomID;}
    std::string getRoomName() const {return roomName;}
    std::string getRoomDescription() const {return roomDescription;}
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    std::vector<NPC*> getNPCs() { return npcs; }
    std::vector<RiddleNPC*> getRiddleNPCs() { return riddleNPCs; }

    //Room actions
    void draw() const;
    bool isWall(int r, int c);
    void addDoor(int r, int c);

    //Adds NPCs, RiddleNPCs or games to room
    void addRiddleNPC(RiddleNPC* riddleNPC, int r, int c);
    void addNPC(NPC* npc, int r, int c);
    void addPuzzle(Puzzle puzzle);
    void addRiddle(Riddle* riddle);

    //Player interactions with room
    void leaveRoom();


};

#endif //FINAL_REPO_LOCAL_ROOM1_H