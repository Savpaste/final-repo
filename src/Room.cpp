#include "Room.h"
using namespace std;


Room::Room(int roomID, string roomName, string roomDescription, int width, int height, Player* player) :
    roomID(roomID),
    roomName(roomName),
    roomDescription(roomDescription),
    startX(1),
    startY(1),
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

//Deep copy constructor
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

//Destructor
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

//Assignment operator
Room& Room::operator = (const Room& other) {
    if (this == &other) return *this;

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

//Function to draw the room
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
bool Room::isWall(int c, int r) {
    if (c < 0 || c >= width || r < 0 || r >= height) {
        return true;
    }
    return grid[r][c] == '#';
}


void Room::leaveRoom() {
}

//Adds a door to the room
void Room::addDoor(int c, int r, int nextRoomID, bool locked, RiddleNPC* rnpc) {
    doors.push_back(Door(c, r, nextRoomID, locked, rnpc));

    // Mark the door on the grid
    if (r >= 0 && r < height && c >= 0 && c < width) {
        grid[r][c] = 'D';
    } else {
        std::cout << "Warning: Door position (" << c << "," << r << ") is out of bounds!\n";
        cout << endl;
    }
}


//Adds an unlock function that is activated when the riddle is solved
bool Room::unlockDoor(int r, int c) {
    for (auto &door : doors) {
        if (door.row == r && door.col == c) {
            if (!door.locked) return true;

            if (door.unlockRiddleNPC) {
                Riddle* riddle = door.unlockRiddleNPC->getRiddle();
                if (!riddle->isSolved()) {
                    if (riddle->ask()) {
                        door.locked = false;
                        grid[door.row][door.col] = 'D';
                        std::cout << "Correct! Door unlocked.\n";
                        return true;
                    }
                    return false;
                } else {
                    door.locked = false;
                    grid[door.row][door.col] = 'D';
                    return true;
                }
            }

            std::cout << "No RiddleNPC assigned to this door. Door stays locked.\n";
            return false;
        }
    }
    return false;
}

//Function that determines the destination that the door leads to
int Room::getDoorDest(int x, int y) {
    for (auto &door : doors) {
        if (door.row == y && door.col == x) {

            // Door is locked and RiddleNPC exists
            if (door.locked) {
                if (door.unlockRiddleNPC && door.unlockRiddleNPC->getRiddle()->isSolved()) {
                    door.locked = false;
                    grid[door.row][door.col] = 'D';
                }
            }

            // If still locked, return -1 so the player cannot move
            if (door.locked) {
                std::cout << "The door is locked. Solve the riddle first!\n";
                return -1;
            }

            return door.goToRoomID; // unlocked, player can move through
        }
    }

    return -1; // no door here
}

void Room::setStartPosition(int x, int y) {
    startX = x;
    startY = y;
}

void Room::addNPC(NPC* npc, int c, int r) {
    npc->setPosition(c, r);
    npcs.push_back(npc);
}

void Room::addRiddleNPC(RiddleNPC* rnpc, int c, int r) {
    rnpc->setPosition(c, r);
    riddleNPCs.push_back(rnpc);
}

void Room::addPuzzle(Puzzle puzzle) {
}

void Room::addRiddle(Riddle* riddle) {
    riddles.push_back(riddle);
}


