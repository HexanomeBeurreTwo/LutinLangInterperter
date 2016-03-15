//
//  LutinLangInterperter
//  E16.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E16_H_
#define STATE_E16_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E16 : public State {
 public:
    E16();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 16;}
};

#endif  // STATE_E16_H_

