//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#include "headers/Board.h"

Board::Board(int size, std::vector<BoardEntity *> snl) {
    this->boardSize = size;
    this->snakesAndLadders = snl;

    for (auto* entity : snl) {
        int start = entity->getStartPosition();
        int end = entity->getEndPosition();

        values[start] = end;
    }
}

int Board::getFinalPosition(int position) const {
    if (values.find(position) == values.end()) {
        return position;
    }
    return values.at(position);
}

int Board::getBoardSize() const {
    return boardSize;
}
