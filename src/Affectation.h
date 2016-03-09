
//
//  LutinLangInterperter
//  Symbol.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//


#ifndef AFFECTATION_H
#define AFFECTATION_H

#include "Instruction.h"
#include "Symbol.h"
#include "Expression.h"


// TODO Gerer la liste des varible et leurs valeurs
// la map Vars

class Affectation : public Instruction {

 public:
    Affectation(Expression *expr,Variable* var) : Instruction(AFFECT),expression(expr),variable(var){} ;
    virtual ~Affectation();
    void print();
    bool execute(Declrs & variables);

 private :
    Expression *expression;
    Variable* variable;
};





#endif  // AFFECTATION_H
