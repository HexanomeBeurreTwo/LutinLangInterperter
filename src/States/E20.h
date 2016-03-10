//
//  LutinLangInterperter
//  E20.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E20_H_
#define STATE_E20_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E20 : public State {
 public:
    E20();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 20;}
};

#endif  // STATE_E20_H_

