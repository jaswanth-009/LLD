#include <iostream>
#include "headers/Game.h"
#include "headers/RowBasedWinningStrategy.h"

int main() {
    Player* p1 = new Player("Jassi", Symbol::symbol_o);
    Player* p2 = new Player("John", Symbol::symbol_x);
    WinningStrategy* ws = new RowBasedWinningStrategy();

    Game* g = new Game(3, p1, p2);
    g->setWinningStrategy(ws);

    g->makeMove(1, 2, p1);
    g->makeMove(2, 2, p2);

    g->makeMove(3, 4, p2); // should display error
    g->printBoard();

    g->makeMove(1,0, p1);
    g->makeMove(2, 1, p2);
    g->makeMove(1, 1, p1); // should announce winner

    g->makeMove(2, 2, p2); // should not allow

    delete p1, p2, g;
    return 0;
}
