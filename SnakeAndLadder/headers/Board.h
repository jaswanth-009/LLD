//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_BOARD_H
#define SNAKEANDLADDER_BOARD_H

#include <unordered_map>
#include <vector>

#include "BoardEntity.h"

class Board {
private:
    int boardSize;
    std::vector<BoardEntity *> snakesAndLadders;
    std::unordered_map<int ,int> values;

public:

    Board(int size, std::vector<BoardEntity* > snl);
    int getBoardSize() const;
    int getFinalPosition(int position) const;

};
#endif //SNAKEANDLADDER_BOARD_H