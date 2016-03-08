#ifndef SYMBOL_H
#define SYMBOL_H

#include "TokenSymbol.h"

class Symbol {

protected:
  TokenSymbol ident;

public:
    Symbol(TokenSymbol id) : ident(id) {}
    virtual ~Symbol() ;
    virtual void print()=0;
    operator int() const { return (int)ident; }

};
#endif // SYMBOL_H
