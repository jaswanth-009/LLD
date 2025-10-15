//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#include "headers/RowBasedWinningStrategy.h"

bool RowBasedWinningStrategy::isWinner(Player *p, Board *board) {
    int n = board->getBoardSize();
    Symbol sym = p->getSymbol();

    for (int i = 0; i < n; i++) {
        bool winner = true;
        for (int j = 0; j < n; j++) {
            Cell* cell = board->getCell(i, j);
            if (cell->getSymbol() != sym) {
                winner = false;
                break;
            }
        }
        if (winner) {
            return true;
        }
    }
    return false;
}
