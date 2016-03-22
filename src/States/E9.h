//
//  LutinLangInterperter
//  E9.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E9_H_
#define STATE_E9_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E9 : public State {
 public:
    E9();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 9;}
};

#endif  // STATE_E9_H_

