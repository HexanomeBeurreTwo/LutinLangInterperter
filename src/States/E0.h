//
//  LutinLangInterperter
//  E0.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E0_H_
#define STATE_E0_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E0 : public State {
 public:
    E0();
    ~E0(){};
    bool transition(Automaton *automaton, ValuableToken t);
    inline int getStateNumber(){return 0;}
};

#endif  // STATE_E0_H_

