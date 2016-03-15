//
//  LutinLangInterperter
//  E2.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E2_H_
#define STATE_E2_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E2 : public State {
 public:
    E2();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 2;}
};

#endif  // STATE_E2_H_

