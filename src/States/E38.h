//
//  LutinLangInterperter
//  E38.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E38_H_
#define STATE_E38_H_

#include "../State.h"
#include "../Symbol.h"
#include "../Automaton.h"

class E38 : public State {
 public:
    E38();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return 38;}
};

#endif  // STATE_E38_H_

