//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_CELL_H
#define TICTACTOE_CELL_H
#include "Symbol.h"

class Cell {
private:
    Symbol symbol;

public:
    Cell();
    bool isEmpty() const;
    void setSymbol(Symbol sym);
    Symbol getSymbol() const;
};
#endif //TICTACTOE_CELL_H