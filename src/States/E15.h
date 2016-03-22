//
//  LutinLangInterperter
//  E15.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E15_H_
#define STATE_E15_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E15 : public State {
 public:
    E15();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 15;}
};

#endif  // STATE_E15_H_

