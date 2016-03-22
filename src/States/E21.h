//
//  LutinLangInterperter
//  E21.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E21_H_
#define STATE_E21_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E21 : public State {
 public:
    E21();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 21;}
};

#endif  // STATE_E21_H_

