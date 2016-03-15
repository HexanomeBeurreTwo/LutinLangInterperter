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
    virtual void print(ostream& os) const =0;
    operator int() const { return (int)ident; }

    friend ostream& operator<< (ostream& os, const Symbol& symbol)
    {
        symbol.print(os);
        return os ;
    }

};



#endif // SYMBOL_H
