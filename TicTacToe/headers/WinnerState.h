//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_WINNERSTATE_H
#define TICTACTOE_WINNERSTATE_H

#include "State.h"

class WinnerState : public State {
public:
    void makeMove(Game* game, Player* p, int r, int c) override;
};

#endif //TICTACTOE_WINNERSTATE_H