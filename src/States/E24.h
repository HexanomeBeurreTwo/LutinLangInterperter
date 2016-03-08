//
//  LutinLangInterperter
//  E24.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E24_H_
#define STATE_E24_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E24 : public State {
 public:
    E24();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 24;}
};

#endif  // STATE_E24_H_

