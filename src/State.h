//
//  LutinLangInterperter
//  State.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//


#ifndef STATE_H_
#define STATE_H_

class Automaton;

#include "Tokens.h"

class State {
 public:
    State() { }
    virtual bool transition(Automaton *automaton, ValuableToken t) = 0;
    virtual int getStateNumber() = 0;
};



#endif  // STATE_H_
