//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#include "headers/Cell.h"

Cell::Cell() {
    symbol = Symbol::symbol_empty;
}

bool Cell::isEmpty() const {
    return symbol == Symbol::symbol_empty;
}

void Cell::setSymbol(Symbol sym) {
    symbol = sym;
}

Symbol Cell::getSymbol() const {
    return symbol;
}