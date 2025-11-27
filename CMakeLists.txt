cmake_minimum_required(VERSION 3.28)
project(final_repo_local)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include
        include/Player.h
        include/NPC.h
        include/Map.h
        include/Game.h
        include/Inventory.h
        include/Items.h
        include/Palace.h
        include/Room.h
        include/Character.h
        include/Puzzle.h
        include/Riddle.h
)

file(GLOB SOURCES "src/*.cpp"
        src/main.cpp
        src/Palace.cpp
        src/Map.cpp
        src/Room.cpp
        src/Player.cpp
        src/NPC.cpp
        src/Inventory.cpp
        src/Items.cpp
        src/Game.cpp
        src/Puzzle.cpp
        src/Riddle.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES}
        src/Main.cpp
        src/Palace.cpp
        src/Character.cpp
        src/Player.cpp
        src/NPC.cpp
        src/Room.cpp
        src/Map.cpp
        src/Game.cpp
        src/Puzzle.cpp
        src/Riddle.cpp
        src/Inventory.cpp
        src/Items.cpp
        include/RiddleNPC.h
        src/RiddleNPC.cpp
)

# 2. CTest Target (Must be defined separately)
enable_testing()

add_executable(test_feature
        tests/test_feature.cpp
        src/Room.cpp
        src/Player.cpp
        src/NPC.cpp
        src/Character.cpp
        src/RiddleNPC.cpp
        src/Map.cpp
        src/Game.cpp
        src/Puzzle.cpp
        src/Riddle.cpp
        src/Inventory.cpp
        src/Items.cpp
)

add_test(NAME FeatureTests COMMAND test_feature)