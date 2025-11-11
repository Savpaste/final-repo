# Implementation Plan

## Feature 1: Start Game
**Trigger**: Player runs the program (game startup)

**Input Needed**:
- None (game starts automatically)

**Implementation Flow**:
1. `main()` creates a `Palace` object and calls `palace.run()`
2. `Palace::run()`:
    - Loads map and rooms
    - Initializes player and NPCs
    - Creates items
    - Displays the introduction and main menu
3. Player begins exploring

**Data Modified**:
- Player object created and initialized
- Map and NPC data loaded into memory

**Completion**:
- Displays starting location and available actions

**Functions Used**:
- `Palace::run()`
- `Room::draw()`
- `Character::setPosition(int, int)`

---

## Feature 2: Move Between Rooms
**Trigger**: Player selects a movement option (W ,S, A, D)

**Input Needed**:
- Direction (char)

**Implementation Flow**:
1. In `Palace::processInput(char)`, input direction/choice
2. Call `Room::leaveRoom()`
3. If valid:
    - Update player coordinates
    - Display new room description
4. If invalid:
    - Display “You hit a wall!”, or "The door is locked!"

**Data Modified**:
- Player’s position (`x`, `y`) updated
- Room ID

**Completion**:
- New room description shown
- New room displayed

**Functions Used**:
- `Game::processInput()`
- `Room::leaveRoom()`
- `Character::setPosition(int, int)`

---

## Feature 3: NPC Interaction
**Trigger**: Player moves into an NPC

**Input Needed**:
- Interact

**Implementation Flow**:
1. `Palace::processInput(char)`
    - Move player into NPC
2. Calls `Player::interact(const NPC&, const Item*, string)`
3. `Player::interact(const NPC&, const Item*, string)`:
    - Gives player option to interact with NPC 
4. Calls `NPC::getDialogue()`
5. `NPC::getDialogue()`
    - Displays the NPC’s dialogue
    - Allows user to converse with NPC
6. May trigger quest or puzzle logic or provide an item depending on NPC type

**Data Modified**:
- Inventory (possibly)
- Game status

**Completion**:
- NPC dialogue displayed on screen
- Item awarded

**Functions Used**:
- `Palace:processInput(char)`
- `Character::setPosition(int, int)`
- `Player::interact(const NPC&, const Item*, string)`
- `NPC::getDialogue()`
- `Room::addNPC()`

---

## Feature 4: Solve Puzzle or Riddle
**Trigger**: Player interacts with game object or NPC

**Input Needed**:
- Player’s puzzle/riddle answer (string)
- Item
- Interact

**Implementation Flow**:
1. Player triggers game 
2. Solver function implements game
3. Player inputs answer or interacts with game
4. `Game::isCorrect()` verifies correctness
5. If correct... reward (e.g., key item)
6. If incorrect... optional penalty or retry prompt

**Data Modified**:
- Puzzle completion state updated
- Inventory may be modified

**Completion**:
- Message displayed based on answer result
- Possible item awarded 

**Functions Used**:
- `Puzzle::solve()`
- `Riddle::solve()`
- `Inventory::addItem(Item)`

---

## Feature 5: Inventory System
**Trigger**: Player picks up, receives or uses an item

**Input Needed**:
- Player action (“pick up” or “use”)
- Interact
- Item name

**Implementation Flow**:
1. `Palace::processInput(char)` detects item-related command
2. If acquiring item:
    - Call `Inventory::addItem(Item&)`
4. If using item:
    - Call `Inventory::useItem(Item&)`
    - Apply item

**Data Modified**:
- Inventory vector
- Game status

**Completion**:
- Updated inventory display or effect applied
- Game solved

**Functions Used**:
- `Inventory::addItem(Item&)`
- `Inventory::useItem(Item&)`

---