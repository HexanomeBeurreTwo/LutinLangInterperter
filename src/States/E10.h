//
//  LutinLangInterperter
//  E10.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E10_H_
#define STATE_E10_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E10 : public State {
 public:
    E10();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 10;}
};

#endif  // STATE_E10_H_

