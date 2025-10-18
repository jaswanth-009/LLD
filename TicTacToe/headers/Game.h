//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H
#include "Board.h"
#include "WinningStrategy.h"
#include "DrawState.h"
#include "GameSubject.h"
#include "WinnerState.h"
#include "InProgressState.h"

class Game: public GameSubject {
private:
    Board* board;
    Player* player1;
    Player* player2;
    Player* curPlayer;
    Player* winner;
    WinningStrategy* winningStrategy;
    State* gameState;
    std::string uid;

public:
    Game(int size, Player* p1, Player* p2);
    void makeMove(int x, int y, Player* p);
    void setWinningStrategy(WinningStrategy* ws);
    void printBoard();
    void setState(State* st);
    Board* getBoard() const;
    Player* getWinner() const;
    void switchCurrentPlayer();
    void setCurrentPlayer(Player* p);
    bool checkWinner();
    Player* getCurrenPlayer();
    State* getWinnerState();
    State* getDrawState();
    void setWinner(Player* p);
    std::string generateHash();
    std::string getUid() const;
    void notifyObservers() override;
};
#endif //TICTACTOE_GAME_H