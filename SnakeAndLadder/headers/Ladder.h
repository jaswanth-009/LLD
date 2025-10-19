//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_LADDER_H
#define SNAKEANDLADDER_LADDER_H
#include "BoardEntity.h"

class Ladder: public BoardEntity {
    public:
    Ladder(int startPosition, int endPosition);
    bool arePositionsValid(int start, int end) override;
};

#endif //SNAKEANDLADDER_LADDER_H