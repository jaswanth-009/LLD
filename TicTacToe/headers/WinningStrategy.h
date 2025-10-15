//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_WINNINGSTRATEGY_H
#define TICTACTOE_WINNINGSTRATEGY_H

#include "Board.h"

class WinningStrategy {
public:
    virtual bool isWinner(Player* p, Board* board) = 0;
};
#endif //TICTACTOE_WINNINGSTRATEGY_H