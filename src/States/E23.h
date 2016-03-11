//
//  LutinLangInterperter
//  E23.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E23_H_
#define STATE_E23_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E23 : public State {
 public:
    E23();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 23;}
};

#endif  // STATE_E23_H_
