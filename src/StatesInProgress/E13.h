//
//  LutinLangInterperter
//  E13.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E13_H_
#define STATE_E13_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E13 : public State {
 public:
    E13();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 13;}
};

#endif  // STATE_E13_H_

