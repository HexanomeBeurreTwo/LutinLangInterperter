//
//  LutinLangInterperter
//  E39.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E39_H_
#define STATE_E39_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E39 : public State {
 public:
    E39();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 39;}
};

#endif  // STATE_E39_H_
