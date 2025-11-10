//
// Created by Avery Williams on 10/24/25.
//

#ifndef FINAL_REPO_LOCAL_MAP_H
#define FINAL_REPO_LOCAL_MAP_H


#include <vector>
#include "Room.h"

//Class for the overall map containing all the rooms
class Map {

    private:
    std::vector<Room> rooms;
    int currentRoomIndex;

    public:
    //Constructor and deconstructor
    Map();
    ~Map();

    //Getters for number of rooms and room indices
    void addRoom(const Room& room);
    std::vector<Room>& getRooms() const;
    int getCurrentRoomIndex() const;

    //Room interactions
    void enterRoom(Room& room);
    void exitRoom(Room& room);

};

#endif //FINAL_REPO_LOCAL_MAP_H