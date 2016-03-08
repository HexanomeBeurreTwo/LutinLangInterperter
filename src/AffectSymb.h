//
//  LutinLangInterperter
//  Symbol.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//


#ifndef AFFECTSYMB_H
#define AFFECTSYMB_H

#include "Instruction.h"
#include "Symbol.h"

class AffectSymb : public Instruction {

 public:
    AffectSymb() : Instruction(AFFECT){} ;
    virtual ~AffectSymb();
    void print();


};





#endif  // AFFECTSYMB_H
