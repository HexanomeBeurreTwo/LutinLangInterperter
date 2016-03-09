#ifndef SYMBOL_H
#define SYMBOL_H

#include "Tokens.h"

#include <map>
#include <iostream>
using namespace std;

class Declaration;

typedef map<string,Declaration*> Declrs;


class Symbol {

protected:
  Tokens ident;

public:
    Symbol(Tokens id) : ident(id) {}
    virtual ~Symbol(){} ;
    virtual void print()=0;
    operator int() const { return (int)ident; }

};
#endif // SYMBOL_H
