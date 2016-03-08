//
//  LutinLangInterperter
//  E3.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E3_H_
#define STATE_E3_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E3 : public State {
 public:
    E3();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 3;}
};

#endif  // STATE_E3_H_

