#include <iostream>
#include "headers/Game.h"
#include "headers/RowBasedWinningStrategy.h"
#include "headers/TicTacToeSystem.h"

int main() {

    Player* p1 = new Player("Jassi", Symbol::symbol_o);
    Player* p2 = new Player("John", Symbol::symbol_x);
    WinningStrategy* ws = new RowBasedWinningStrategy();
    TicTacToeSystem* sys = TicTacToeSystem::getInstance();

    std::string g1 = sys->createGame(p1, p2, 3);
    sys->setWinningStrategy(g1, ws);

    sys->makeMove(g1, p1, 1,2);
    sys->makeMove(g1, p2, 2,2);
    sys->makeMove(g1, p2, 3,4); // player error

    sys->getGame(g1)->getBoard();

    sys->makeMove(g1, p1, 1,0);
    sys->makeMove(g1, p2, 2,1);
    sys->makeMove(g1, p1, 1,1); // winner

    sys->makeMove(g1, p2, 2,2); // should not allow

    sys->printScoreBoard();

    delete p1, p2;
    return 0;
}
