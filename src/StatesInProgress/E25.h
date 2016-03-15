//
//  LutinLangInterperter
//  E25.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E25_H_
#define STATE_E25_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E25 : public State {
 public:
    E25();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 25;}
};

#endif  // STATE_E25_H_

