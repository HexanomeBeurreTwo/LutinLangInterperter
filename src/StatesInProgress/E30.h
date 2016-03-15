//
//  LutinLangInterperter
//  E30.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E30_H_
#define STATE_E30_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E30 : public State {
 public:
    E30();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 30;}
};

#endif  // STATE_E30_H_

