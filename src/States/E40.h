//
//  LutinLangInterperter
//  E40.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E40_H_
#define STATE_E40_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E40 : public State {
 public:
    E40();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 40;}
};

#endif  // STATE_E40_H_

