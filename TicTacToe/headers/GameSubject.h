//
// Created by Jassvanthh Kunjeti on 18/10/25.
//

#ifndef TICTACTOE_GAMESUBJECT_H
#define TICTACTOE_GAMESUBJECT_H

#include <vector>

#include "GameObserver.h"

class GameSubject {
    public:
        std::vector<GameObserver*> observers;
        void addObserver(GameObserver* observer);
        void removeObserver(GameObserver* observer);
        virtual void notifyObservers() = 0;
};
#endif //TICTACTOE_GAMESUBJECT_H