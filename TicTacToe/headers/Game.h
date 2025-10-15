//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H
#include "Board.h"
#include "Status.h"
#include "WinningStrategy.h"

class Game {
private:
    Board* board;
    Player* player1;
    Player* player2;
    Player* curPlayer;
    Player* winner;
    Status  status;
    WinningStrategy* winningStrategy;

public:
    Game(int size, Player* p1, Player* p2);
    void makeMove(int x, int y, Player* p);
    void setWinningStrategy(WinningStrategy* ws);
    void printBoard();
};
#endif //TICTACTOE_GAME_H