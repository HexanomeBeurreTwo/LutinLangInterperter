//
//  LutinLangInterperter
//  E26.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E26_H_
#define STATE_E26_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E26 : public State {
 public:
    E26();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 26;}
};

#endif  // STATE_E26_H_

