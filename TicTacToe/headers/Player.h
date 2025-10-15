//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_PLAYER_H
#define TICTACTOE_PLAYER_H

#include <string.h>
#include <string>

#include "Symbol.h"

class Player {
private:
    std::string name;
    Symbol symbol;

public:
    Player(std::string name, Symbol sym);
    Symbol getSymbol() const;
    std::string getName() const;
};
#endif //TICTACTOE_PLAYER_H