# Checkpoint 1 Test Cases

## Feature: Room and Map Core Functionality (Player/NPC/Draw)

### Test Setup
* **Test file:** `tests/test_feature.cpp`
* **Build system:** CMake with CTest
* **Run command:** `ctest --verbose`

---

### Test 1: Normal Operation
* **What it tests**: Creating a room and successfully adding both the **Player** and a separate **NPC**. Verifies the initial positions are set correctly.
* **Expected result**: The Player's position is set at coordinates **(1, 1)**, and the NPC is successfully added to the room at coordinates **(3, 3)**.
* **Result**: ✅ Pass

---

### Test 2: Boundary Conditions
* **What it tests**: Verifying the **Map Drawing logic** by checking if the Player (`@`) and an NPC (using `B` as the symbol) are placed at the exact expected **string index** of the captured map output for a 4x4 room.
* **Expected result**: The map output contains the Player character (`@`) at the coordinates **(1, 1)**, and the NPC (`B`) at coordinates **(2, 1)**.
* **Result**: ✅ Pass

---

### Test 3: Edge Case
* **What it tests**: Verifying that the map correctly reflects the Player's state after a **movement input**. Tests moving the player from the initial position to an open space **(3, 3)**.
* **Expected result**: The Player's position is successfully changed to **(3, 3)**, and the map output contains the Player character (`@`) at the corresponding new index.
* **Result**: ✅ Pass


# CTest Output Analysis

## What I Implemented
* **Implementation Focus**: The test executable **`test_feature`** ran and successfully verified the code.
* **Functionality Added**: All three tests—Normal Operation, Boundary Conditions, and Edge Case—ran successfully. **\#CTestSuccess \#BuildVerified**

---

## Challenges I Faced
* **Core Challenge**: The test successfully ran past the linker errors, confirming the manual correction of the `operator<<` definition in `src/Items.cpp` worked.

---

## What I Learned
* **Test Verification**: Learned that `ctest --verbose` provides detailed lifecycle logging (e.g., `Character created`, `Player entered the Palace`, `NPC destroyed`) that confirms the flow of the code being tested.

---

## Testing Results
* **Outcome**: **100% tests passed, 0 tests failed out of 1.**
* **Run Time**: Total Test time (real) = 0.19 sec.

---

## CTest Output 
* **Note**: This confirms the `test_feature` executable was successfully compiled and executed.

```bash
averywilliams@Averys-MacBook-Pro build % ctest --verbose
UpdateCTestConfiguration from :/Users/averywilliams/CLionProjects/final-repo-local/build/DartConfiguration.tcl
Test project /Users/averywilliams/CLionProjects/final-repo-local/build
Constructing a list of tests
... (output omitted) ...
1: === Running Tests for Puzzle Palace Room Feature ===
1: Test 1: Normal Operation (Adding Player & NPC)...Character TestHero created.
... (detailed PASS logs) ...
1: PASSED
...
1: Test 2: Boundary Conditions (Draw Output)...Character Tester created.
... (detailed PASS logs) ...
1: PASSED
...
1: Test 3: Edge Case (Movement and Draw)...Character Tester created.
... (detailed PASS logs) ...
1: PASSED
1/1 Test #1: FeatureTests ..................... Passed 0.18 sec
100% tests passed, 0 tests failed out of 1
Total Test time (real) = 0.19 sec