//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H
#include <vector>

#include "Cell.h"
#include <vector>
#include "Player.h"

class Board {
    private:
        int size;
        int movesCount;
        std::vector<std::vector<Cell*>> board;
    public:
        Board(int n);
        bool placeSymbol(int x, int y, Player* p);
        int getBoardSize() const;
        Cell* getCell(int x, int y);
        void printBoard() const;
        int getMovesCount();
};
#endif //TICTACTOE_BOARD_H