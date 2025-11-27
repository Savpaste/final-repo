#include "Map.h"
using namespace std;


Map::Map()
    : currentRoomID(0) {
}

Map::~Map() {

}

void Map::addRoom(Room* room) {
    rooms.push_back(room);
}

void Map::drawCurrentRoom() const {
    if (currentRoomID >= 0 && currentRoomID < rooms.size()) {
        rooms[currentRoomID]->draw();
    }
}


bool Map::isWall(int x, int y)  {
    if (currentRoomID < 0 || currentRoomID >= rooms.size())
        return true;
    return rooms[currentRoomID]->isWall(x, y);
}


