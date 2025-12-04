#include "Map.h"
using namespace std;


Map::Map()
    : currentRoomID(0),
      currentRoom(nullptr) {
}

Map::~Map() {
    for (Room* r : rooms) delete r;
}

void Map::addRoom(Room* room) {
    rooms.push_back(room);
    if (!currentRoom) {
        currentRoom = room;
        currentRoomID = room->getRoomID();
    }
}

void Map::changeRoom(int roomID) {
    for (Room* r : rooms) {
        if (r->getRoomID() == roomID) {
            currentRoom = r;
            currentRoomID = roomID;
            return;
        }
    }
    std::cout << "No room with ID " << roomID << " found!\n";
}

void Map::drawCurrentRoom() const {
    if (currentRoom) {          // use the currentRoom pointer
        currentRoom->draw();
    } else {
        std::cout << "No room to draw!\n";
    }
}

bool Map::isWall(int x, int y)  {
    if (!currentRoom)
        return true;
    return currentRoom->isWall(x, y);
}


/*bool Map::isWall(int x, int y)  {
    if (currentRoomID < 0 || currentRoomID >= rooms.size())
        return true;
    return rooms[currentRoomID]->isWall(x, y);
}*/



