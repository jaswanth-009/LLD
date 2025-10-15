//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_ROWBASEDWINNINGSTRATEGY_H
#define TICTACTOE_ROWBASEDWINNINGSTRATEGY_H

#include "WinningStrategy.h"

class RowBasedWinningStrategy : public WinningStrategy {
    public:
    bool isWinner(Player* p, Board* board) override;
};
#endif //TICTACTOE_ROWBASEDWINNINGSTRATEGY_H