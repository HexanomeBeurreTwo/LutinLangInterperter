//
//  LutinLangInterperter
//  E37.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E37_H_
#define STATE_E37_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E37 : public State {
 public:
    E37();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 37;}
};

#endif  // STATE_E37_H_

