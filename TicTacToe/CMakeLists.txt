cmake_minimum_required(VERSION 4.0)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 20)

add_executable(TicTacToe main.cpp
        Player.cpp
        Cell.cpp
        Board.cpp
        Game.cpp
        RowBasedWinningStrategy.cpp
        ColumnBasedWinningStrategy.cpp
        InProgressState.cpp
        WinnerState.cpp
        DrawState.cpp
        TicTacToeSystem.cpp
        GameSubject.cpp
        ScoreBoard.cpp)
