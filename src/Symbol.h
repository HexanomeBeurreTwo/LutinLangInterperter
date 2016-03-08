//
//  LutinLangInterperter
//  Symbol.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//


#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol {
protected:
  int ident;

 public:
    virtual Symbol(int id) : ident(id) {} = 0;
    virtual ~Symbol() {};
    virtual void print();
    operator int() const { return ident; }
};



#endif  // SYMBOL_H
