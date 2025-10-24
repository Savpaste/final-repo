cmake_minimum_required(VERSION 3.28)
project(final_repo_local)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES}
        src/Main.cpp)