//
//  LutinLangInterperter
//  E22.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E22_H_
#define STATE_E22_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E22 : public State {
 public:
    E22();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 22;}
};

#endif  // STATE_E22_H_

