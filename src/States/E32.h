//
//  LutinLangInterperter
//  E32.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E32_H_
#define STATE_E32_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E32 : public State {
 public:
    E32();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 32;}
};

#endif  // STATE_E32_H_

