# Checkpoint 2 Test Cases

## Feature: Riddle Logic and Implementation

### Test Setup
* **Test file:** `tests/test_feature.cpp`
* **Build system:** CMake with CTest
* **Run command:** `ctest --verbose`

---

### Test 1: Normal Operation
* **What it tests**: Normal riddle solve operation
* **Expected result**: The player will input the correct answer and get validation for the correct answer
* **Result**: ✅ Pass

---

### Test 2: Boundary Conditions
* **What it tests**: Attempt to solve the riddle twice after is has already been solved
* **Expected result**: The riddle remains solved, and the second interaction does not change the state or cause an error
* **Result**: ✅ Pass

---

### Test 3: Edge Case
* **What it tests**: Multiple incorrect answers followed by a correct answer
* **Expected Results**: The riddle is not marked as solved until the correct answer is given, and all interactions are handled without hanging or crashing
* **Result**: ✅ Pass

---

# CTest Output Analysis

---

## What I Implemented
* **Implementation Focus**: The test executable **`test_feature`** ran and successfully verified the riddle feature logic
* **Functionality Added**: All three tests—Normal Operation, Boundary Conditions, and Edge Case—ran successfully without blocking

---

## Challenges I Faced
* **Core Challenge**: Originally, tests hung because RiddleNPC::interact() and riddle->ask() were waiting for real user input. This was resolved by adjusting the code to allow automated input streams, ensuring the tests could run non-interactively
* **Additional Challenge**: Ensuring test inputs matched the expected prompts in the riddle feature so the automated tests would pass

---

## What I Learned
* **Test Verification**: Writing automated tests requires anticipating how functions handle input
* **Debugging**: Reading CTest output and checking for hangs or blocked input helps identify where feature logic needs adjustment

---

## Testing Results
* **Outcome**: **100% tests passed, 0 tests failed out of 1.**
* **Run Time**: Total Test time (real) = 0.20 sec.

---

## CTest Output
* **Note**: This confirms the `test_feature` executable was successfully compiled and executed, , and that the riddle feature behaves correctly under normal, edge, and boundary conditions

---

```bash

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
1: === Running Riddle Feature Tests ===
1:
1: All tests PASSED!
1/1 Test #1: FeatureTests .....................   Passed    0.20 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.20 sec

