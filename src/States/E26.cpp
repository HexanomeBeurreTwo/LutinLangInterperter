//
//  LutinLangInterperter
//  E26.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E26.h"

E26::E26() : State() { }

bool E26::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case END:
	    ValuableToken t;
	    t.token = LI;
	    return automaton->reduce(2, t, 2);
    default: return false; // Error !
  }
  return false;
}

