//
// Created by Jassvanthh Kunjeti on 19/10/25.
//

#ifndef SNAKEANDLADDER_BOARDENTITY_H
#define SNAKEANDLADDER_BOARDENTITY_H

class BoardEntity {
    private:
        int startPosition;
        int endPosition;
    public:
    BoardEntity(int startPosition, int endPosition) {
        this->startPosition = startPosition;
        this->endPosition = endPosition;
    }

    int getStartPosition() {
        return this->startPosition;
    }

    int getEndPosition() {
        return this->endPosition;
    }

    virtual bool arePositionsValid(int start, int end) = 0;
    virtual ~BoardEntity() = default;
};
#endif //SNAKEANDLADDER_BOARDENTITY_H