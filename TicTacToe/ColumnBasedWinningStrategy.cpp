//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#include "headers/ColumnBasedWinningStrategy.h"

bool ColumnBasedWinningStrategy::isWinner(Player *p, Board *board) {
    int n = board->getBoardSize();

    for (int c = 0; c < n; c++) {
        bool winner = true;

        for (int r = 0; r < n; r++) {
            Cell* cell = board->getCell(r, c);
            Symbol sym = cell->getSymbol();
            Symbol pSym = p->getSymbol();
            if (sym != pSym) {
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
