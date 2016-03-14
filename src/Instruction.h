//
//  LutinLangInterperter
//  Symbol.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//


#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Symbol.h"
#include "Tokens.h"


class Instruction : public Symbol {

 public:
    Instruction(Tokens id) : Symbol(id){};
    virtual ~Instruction(){} ;
    virtual void print(ostream& os) const = 0;
    virtual bool execute(Declrs & variables) = 0;


};



#endif  // INSTRUCTION_H
