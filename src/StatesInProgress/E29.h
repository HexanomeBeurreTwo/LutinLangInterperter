//
//  LutinLangInterperter
//  E29.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E29_H_
#define STATE_E29_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E29 : public State {
 public:
    E29();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 29;}
};

#endif  // STATE_E29_H_

