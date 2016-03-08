//
//  LutinLangInterperter
//  E12.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E12_H_
#define STATE_E12_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E12 : public State {
 public:
    E12();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 12;}
};

#endif  // STATE_E12_H_

