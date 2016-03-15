//
//  LutinLangInterperter
//  E34.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E34_H_
#define STATE_E34_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E34 : public State {
 public:
    E34();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 34;}
};

#endif  // STATE_E34_H_

