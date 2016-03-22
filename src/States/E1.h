//
//  LutinLangInterperter
//  E1.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E1_H_
#define STATE_E1_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E1 : public State {
 public:
    E1();
    ~E1(){};
    bool transition(Automaton *automaton, ValuableToken t);
    inline int getStateNumber(){return 1;}
};

#endif  // STATE_E1_H_

