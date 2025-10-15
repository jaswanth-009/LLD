//
// Created by Jassvanthh Kunjeti on 14/10/25.
//

#ifndef TICTACTOE_SYMBOL_H
#define TICTACTOE_SYMBOL_H

#include <string>

enum Symbol {
    symbol_x,
    symbol_o,
    symbol_empty
};

inline std::string getSymbolName(Symbol sym) {
    switch (sym) {
        case symbol_x: return "x";
        case symbol_o: return "o";
        case symbol_empty: return " ";
        default: return " ?";
    }
    return "";
}

#endif //TICTACTOE_SYMBOL_H