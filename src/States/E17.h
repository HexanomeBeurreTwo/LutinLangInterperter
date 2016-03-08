//
//  LutinLangInterperter
//  E17.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E17_H_
#define STATE_E17_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E17 : public State {
 public:
    E17();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 17;}
};

#endif  // STATE_E17_H_

