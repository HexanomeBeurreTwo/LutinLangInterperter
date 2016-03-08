//
//  LutinLangInterperter
//  Symbol.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights 

#ifndef SYMBOL_H
#define SYMBOL_H

#include "TokenSymbol.h"

class Symbol {

protected:
  TokenSymbol ident;

public:
    Symbol(TokenSymbol id) : ident(id) {} 
    virtual ~Symbol() ;
    virtual void print();
    operator int() const { return (int)ident; }

};



#endif  // SYMBOL_H
