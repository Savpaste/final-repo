# Checkpoint 3 Test Cases

## Feature: Room Transition Implementation

### Test Setup
* **Test file:** tests/test_feature.cpp
* **Build system:** CMake with CTest
* **Run command:** ctest --verbose

---

### Test 1: Normal Operation
* **What it tests**: Player steps on a valid door tile and transitions to the next room
* **Expected result**: The map updates to the correct room, and the player's position is initialized correctly
* **Player Position Check**: After transition, player should be at the new room's startX and startY
* **Result**: ✅ Pass

---

### Test 2: Edge Case
* **What it tests**: Player steps on a tile that is NOT a door
* **Expected result**: The room does not change, and the player's position remains the same
* **Player Position Check**: Player's coordinates remain unchanged
* **Result**: ✅ Pass

---

### Test 3: Boundary / Integration
* **What it tests**: Chained room transitions — player moves through multiple doors sequentially
* **Expected Results**: Each room change occurs in the correct order, and the player ends up in the expected final room
* **Player Position Check**: Player coordinates update correctly with each room change
* **Result**: ✅ Pass

---

# CTest Output Analysis

---

## What I Implemented
* **Implementation Focus**: The test executable test_feature successfully verified room transition logic.
* **Functionality Added**: Normal operation, edge cases, and integration/boundary room transitions were all tested and passed.

---

## Challenges I Faced
* **Core Challenge**: Ensuring the player’s position updates correctly on each room change and that multiple rooms chained properly.
* **Additional Challenge**: Automatically checking that the room ID and player position update correctly, without needing any user input.

---

## What I Learned
* **Test Verification**: Tests for room transitions require checking both the map’s current room and the player’s X/Y coordinates.
* **Debugging**: Making sure the player coordinates don't have multiple inputs.

---

## Testing Results
* **Outcome**: 100% tests passed, 0 tests failed out of 1
* **Run Time**: Total Test time (real) = 0.23 sec

```bash

averywilliams@MacBookPro build % ctest --verbose
UpdateCTestConfiguration  from :/Users/averywilliams/CLionProjects/final-repo-local/build/DartConfiguration.tcl
Test project /Users/averywilliams/CLionProjects/final-repo-local/build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: FeatureTests

1: Test command: /Users/averywilliams/CLionProjects/final-repo-local/build/test_feature
1: Working Directory: /Users/averywilliams/CLionProjects/final-repo-local/build
1: Test timeout computed to be: 10000000
1: 
1: === Running Room Transition Feature Tests ===
1: 
1: Character Tester created.
1: 
1: Player Tester has entered the Palace.
1: 
1: 
1: === Running Test: Normal Room Transition ===
1: PASS: Normal room transition works.
1: 
1: === Running Test: Non-Door Tile Should Not Change Room ===
1: PASS: Non-door tile does not change room.
1: 
1: === Running Test: Multi-Room Chain Transition ===
1: PASS: Multi-step room transition chain works.
1: 
1: All tests PASSED!
1/1 Test #1: FeatureTests .....................   Passed    0.23 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.23 sec
