//
//  LutinLangInterperter
//  E8.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E8_H_
#define STATE_E8_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E8 : public State {
 public:
    E8();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 8;}
};

#endif  // STATE_E8_H_

