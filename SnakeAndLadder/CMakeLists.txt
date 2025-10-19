cmake_minimum_required(VERSION 4.0)
project(SnakeAndLadder)

set(CMAKE_CXX_STANDARD 20)

add_executable(SnakeAndLadder main.cpp
        Player.cpp
        Snake.cpp
        Ladder.cpp
        Dice.cpp
        Board.cpp
        Game.cpp
        SnakeAndLadder.cpp)
