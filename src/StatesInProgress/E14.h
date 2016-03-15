//
//  LutinLangInterperter
//  E14.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E14_H_
#define STATE_E14_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E14 : public State {
 public:
    E14();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 14;}
};

#endif  // STATE_E14_H_

