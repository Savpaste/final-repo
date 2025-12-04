#ifndef FINAL_REPO_LOCAL_MAP_H
#define FINAL_REPO_LOCAL_MAP_H


#include <vector>
#include "Room.h"

//Class for the overall map containing all the rooms
class Map {

    private:
    std::vector<Room*> rooms;
    int currentRoomID;
    Room* currentRoom;


    public:
    //Constructor and deconstructor
    Map();
    ~Map();

    //Getters for number of rooms and room indices
    std::vector<Room*>& getRooms() { return rooms; }
    int getCurrentRoomID() const { return currentRoomID; };
    Room* getCurrentRoom() { return currentRoom; };
    int getTotalRooms() const { return rooms.size(); };

    //Map actions
    void addRoom(Room* room);
    void changeRoom(int roomID);

    //Function to draw the current room the player is in
    void drawCurrentRoom() const;

    //Function for wall logic
    bool isWall(int x, int y);

};

#endif //FINAL_REPO_LOCAL_MAP_H