//
//  LutinLangInterperter
//  E33.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E33_H_
#define STATE_E33_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E33 : public State {
 public:
    E33();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 33;}
};

#endif  // STATE_E33_H_

