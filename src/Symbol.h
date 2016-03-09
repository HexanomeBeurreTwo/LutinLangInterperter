#ifndef SYMBOL_H
#define SYMBOL_H

#include "TokenSymbol.h"

#include <map>
#include <iostream>
using namespace std;

class Declaration;

typedef map<string,Declaration*> Declrs;


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
