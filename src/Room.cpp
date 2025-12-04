#include "Room.h"
using namespace std;


Room::Room(int roomID, string roomName, string roomDescription, int width, int height, Player* player) :
    roomID(roomID),
    roomName(roomName),
    roomDescription(roomDescription),
    player(player),
    width(width),
    height(height) {

    grid = new char* [height];

    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
    }

    //Creates a grid with '#' for walls and '.' for open spaces
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (r == 0 || c == 0 || r == height - 1 || c == width - 1) {
                grid[r][c] = '#'; // this is a wall
            } else {
                grid[r][c] = '.'; // this is just space
            }

        }
    }
    player->setPosition(1, 1); //Sets players initial position to (1, 1)
}

Room::Room(const Room& other)
    : roomID(other.roomID),
      width(other.width),
      height(other.height),
      roomName(other.roomName),
      roomDescription(other.roomDescription),
      puzzles(other.puzzles),
      riddles(other.riddles),
      npcs(other.npcs),
      riddleNPCs(other.riddleNPCs),
      player(other.player) {

    grid = new char*[height];
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        for (int j = 0; j < width; j++) {
            grid[i][j] = other.grid[i][j];
        }
    }
}

Room::~Room() {
    for (int i = 0; i < height; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    // Delete normal NPCs
    for (NPC* npc : npcs) {
        delete npc;
    }

    // Delete RiddleNPCs
    for (RiddleNPC* rnpc : riddleNPCs) {
        delete rnpc;
    }
}

Room& Room::operator = (const Room& other) {
    if (this == &other) return *this; // self-assignment check

    // Copy simple members
    roomID = other.roomID;
    width = other.width;
    height = other.height;
    roomName = other.roomName;
    roomDescription = other.roomDescription;

    // Copy grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = other.grid[i][j];
        }
    }

    // Copy player and NPCs
    player = other.player;          // object copy
    npcs = other.npcs;
    riddleNPCs = other.riddleNPCs;
    // vector copy

    // Copy puzzles and riddles
    puzzles = other.puzzles;
    riddles = other.riddles;

    return *this;
}

void Room::draw() const {
    //Inserts the player symbol
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (player && player->getX() == c && player->getY() == r) {
                cout << "@";
            } else {
                bool found = false;

                // Check normal NPCs and inserts sybmol
                for (auto& npc : npcs) {
                    if (npc->getX() == c && npc->getY() == r) {
                        cout << npc->getSymbol();
                        found = true;
                        break;
                    }
                }

                // Check RiddleNPCs and inserts symbol
                if (!found) {
                    for (auto& rnpc : riddleNPCs) {
                        if (rnpc->getX() == c && rnpc->getY() == r) {
                            cout << rnpc->getSymbol();
                            found = true;
                            break;
                        }
                    }
                }

                if (!found) {
                    cout << grid[r][c];
                }
            }
        }
        cout << endl;
    }
}

//Function to draw a wall
bool Room::isWall(int r, int c) {
    if (r < 0 || r >= width || c < 0 || c >= height) {
        return true;
    }
    return grid[c][r] == '#';
}

void Room::leaveRoom() {
}

void Room::addDoor(int r, int c, int nextRoomID) {
    // Store door info
    doors.push_back(Door(r, c, nextRoomID));

    // Mark the door on the grid
    if (r >= 0 && r < height && c >= 0 && c < width) {
        grid[r][c] = 'D';  // 'D' represents a door
    } else {
        std::cout << "Warning: Door position (" << r << "," << c << ") is out of bounds!\n";
    }
}

int Room::getDoorDest(int r, int c) const {
    for (const auto& door : doors) {
        if (door.row == r && door.col == c) {
            return door.goToRoomID;
        }
    }
    return -1;  // not a door
}

void Room::addNPC(NPC* npc, int r, int c) {
    npc->setPosition(r, c);
    npcs.push_back(npc);
}

void Room::addRiddleNPC(RiddleNPC* rnpc, int r, int c) {
    rnpc->setPosition(r, c);
    riddleNPCs.push_back(rnpc);
}

void Room::addPuzzle(Puzzle puzzle) {
}

void Room::addRiddle(Riddle* riddle) {
    riddles.push_back(riddle);
}


