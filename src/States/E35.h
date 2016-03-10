//
//  LutinLangInterperter
//  E35.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E35_H_
#define STATE_E35_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E35 : public State {
 public:
    E35();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 35;}
};

#endif  // STATE_E35_H_

