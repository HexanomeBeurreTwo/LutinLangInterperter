//
//  LutinLangInterperter
//  E11.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E11_H_
#define STATE_E11_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E11 : public State {
 public:
    E11();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 11;}
};

#endif  // STATE_E11_H_

