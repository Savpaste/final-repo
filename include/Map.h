#ifndef FINAL_REPO_LOCAL_MAP_H
#define FINAL_REPO_LOCAL_MAP_H


#include <vector>
#include "Room.h"

//Class for the overall map containing all the rooms
class Map {

    private:
    std::vector<Room*> rooms;
    int currentRoomID;

    public:
    //Constructor and deconstructor
    Map();
    ~Map();

    //Getters for number of rooms and room indices
    void addRoom(Room* room);
    std::vector<Room*>& getRooms() { return rooms; }
    int getCurrentRoomID() const { return currentRoomID; };

    //Function to draw the current room the player is in
    void drawCurrentRoom() const;

    //Function for wall logic
    bool isWall(int x, int y);


};

#endif //FINAL_REPO_LOCAL_MAP_H