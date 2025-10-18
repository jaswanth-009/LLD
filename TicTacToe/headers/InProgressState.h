//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_INPROGRESSSTATE_H
#define TICTACTOE_INPROGRESSSTATE_H
#include "State.h"

class InProgressState : public State {
    public:
        void makeMove(Game* game, Player* p, int r, int c) override;
};
#endif //TICTACTOE_INPROGRESSSTATE_H