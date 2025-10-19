//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_SNAKE_H
#define SNAKEANDLADDER_SNAKE_H
#include "BoardEntity.h"


class Snake: public BoardEntity {
public:
    Snake(int startPosition, int endPosition);
    bool arePositionsValid(int start, int end) override;
};

#endif //SNAKEANDLADDER_SNAKE_H