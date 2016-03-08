//
//  LutinLangInterperter
//  E31.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E31_H_
#define STATE_E31_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E31 : public State {
 public:
    E31();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 31;}
};

#endif  // STATE_E31_H_

