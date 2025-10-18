//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_TICTACTOESYSTEM_H
#define TICTACTOE_TICTACTOESYSTEM_H
#include <mutex>
#include <unordered_map>
#include "Game.h"
#include "ScoreBoard.h"

class TicTacToeSystem {
private:
    static std::mutex m;
    static std::unordered_map<std::string, Game*> games;
    static ScoreBoard* sb;
    TicTacToeSystem();

public:

    static TicTacToeSystem* instance;
    static TicTacToeSystem* getInstance();
    static void makeMove(std::string uid, Player* p, int x, int y);
    static std::string createGame(Player* p1, Player* p2, int n);
    static Game* getGame(std::string gid);
    static void setWinningStrategy(std::string uid, WinningStrategy* ws);
    static void printScoreBoard();
    ~TicTacToeSystem();


    TicTacToeSystem(const TicTacToeSystem& other) = delete;
    TicTacToeSystem& operator=(const TicTacToeSystem& other) = delete;
};

#endif //TICTACTOE_TICTACTOESYSTEM_H