//
//  LutinLangInterperter
//  E5.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E5_H_
#define STATE_E5_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E5 : public State {
 public:
    E5();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 5;}
};

#endif  // STATE_E5_H_

