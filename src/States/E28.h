//
//  LutinLangInterperter
//  E28.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E28_H_
#define STATE_E28_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E28 : public State {
 public:
    E28();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 28;}
};

#endif  // STATE_E28_H_

