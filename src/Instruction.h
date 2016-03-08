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

class Instruction : public Symbol {

 public:
    Instruction(TokenSymbol id) : Symbol(id){};
    virtual ~Instruction() ;


};



#endif  // INSTRUCTION_H
