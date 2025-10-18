//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_DRAWSTATE_H
#define TICTACTOE_DRAWSTATE_H

#include "State.h"

class DrawState : public State {
public:
    void makeMove(Game* game, Player* p, int r, int c) override;
};


#endif //TICTACTOE_DRAWSTATE_H