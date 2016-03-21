//
//  LutinLangInterperter
//  E27.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E27_H_
#define STATE_E27_H_

#include "../State.h"
#include "../Tokens.h"
#include "../Automaton.h"

class E27 : public State {
 public:
    E27();
    bool transition(Automaton *automaton, ValuableToken s);
    inline int getStateNumber(){return 27;}
};

#endif  // STATE_E27_H_

