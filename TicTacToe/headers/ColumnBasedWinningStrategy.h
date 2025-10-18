//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_COLUMNBASEDWINNINGSTRATEGY_H
#define TICTACTOE_COLUMNBASEDWINNINGSTRATEGY_H


#include "RowBasedWinningStrategy.h"

class ColumnBasedWinningStrategy : public RowBasedWinningStrategy {
    public:
        bool isWinner(Player *p, Board *board) override;
};
#endif //TICTACTOE_COLUMNBASEDWINNINGSTRATEGY_H