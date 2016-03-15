//
//  LutinLangInterperter
//  E19.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E19_H_
#define STATE_E19_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E19 : public State {
 public:
    E19();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 19;}
};

#endif  // STATE_E19_H_

