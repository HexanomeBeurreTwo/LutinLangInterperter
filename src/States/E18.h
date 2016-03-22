//
//  LutinLangInterperter
//  E18.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E18_H_
#define STATE_E18_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E18 : public State {
 public:
    E18();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 18;}
};

#endif  // STATE_E18_H_

