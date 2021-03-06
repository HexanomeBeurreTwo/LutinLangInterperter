//
//  LutinLangInterperter
//  E4.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E4_H_
#define STATE_E4_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E4 : public State {
 public:
    E4();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 4;}
};

#endif  // STATE_E4_H_

