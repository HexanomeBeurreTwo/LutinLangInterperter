
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
#include "Expression.h"


// TODO Gerer la liste des varible et leurs valeurs
// la map Vars

class AffectSymb : public Instruction {

 public:
    AffectSymb(Expression *expr,Variable var) : Instruction(AFFECT),expression(expr),variable(var){} ;
    virtual ~AffectSymb();
    void print();
 private :
    Expression *expression;
    Variable variable;
};





#endif  // AFFECTSYMB_H
