//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#include "headers/Board.h"
#include <iostream>

Board::Board(int n) {
    size = n;
    movesCount = 0;

    board.resize(size);

    for (int i = 0; i <size; i++) {
        board[i].resize(size);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = new Cell();
        }
    }
    std::cout << "Created a board of size: " << size << std::endl;
}

bool Board::placeSymbol(int x, int y, Player *p) {

    if (x < 0 || x >= size || y < 0 || y >= size) {
        std::cout << "Invalid coordinates entered." << std::endl;
        return false;
    }

    Cell* cell = board[x][y];

    if (!cell->isEmpty()) {
        std::cout << "Cell [" << x << "][" << y << "] is already filled\n";
        return false;
    }

    cell->setSymbol(p->getSymbol());
    movesCount++;

    std::cout << "Updated cell[" << x << "][" << y << "] with symbol: " << p->getSymbol() << std::endl;
    return true;
}

int Board::getBoardSize() const {
    return size;
}

Cell* Board::getCell(int x, int y) {
    return board[x][y];
}

void Board::printBoard() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << getSymbolName(board[i][j]->getSymbol()) << " ";
        }
        std::cout << "\n";
    }
}

int Board::getMovesCount() {
    return movesCount;
}


