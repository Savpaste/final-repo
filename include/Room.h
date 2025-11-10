//
// Created by Avery Williams on 10/25/25.
//

#ifndef FINAL_REPO_LOCAL_ROOM1_H
#define FINAL_REPO_LOCAL_ROOM1_H


#include <iostream>
#include <vector>
#include "Player.h"
#include "NPC.h"
#include "Puzzle.h"
#include "Riddle.h"

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
    std::vector <Riddle> riddles;
    std::vector <NPC> npcs;
    Player* player;

    public:
    //Constructor and deconstructor
    Room(int roomID, const std::string& roomName, const std::string& roomDescription, int width, int height, Player* player);
    Room(const Room& other);
    ~Room();

    //Assignment operator
    Room& operator=(const Room& other);

    //Getters for room features
    int getRoomID() const {return roomID;}
    std::string getRoomName() const {return roomName;}
    std::string getRoomDescription() const {return roomDescription;}
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    //Room actions
    void draw();
    bool isWall(int r, int c);

    //Adds NPCs or games to room
    void addNPC(NPC& npc);
    void addPuzzle(Puzzle& puzzle);
    void addRiddle(Riddle& riddle);

    //Player interactions with room
    void enter(Player* p);
    void leave();


};

#endif //FINAL_REPO_LOCAL_ROOM1_H