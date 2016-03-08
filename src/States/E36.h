//
//  LutinLangInterperter
//  E36.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E36_H_
#define STATE_E36_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E36 : public State {
 public:
    E36();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 36;}
};

#endif  // STATE_E36_H_

