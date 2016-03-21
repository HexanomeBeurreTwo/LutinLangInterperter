//
//  LutinLangInterperter
//  E36.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E36.h"

E36::E36() : State() { }

bool E36::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case PLUS:
    case MINUS:
    case MULT:
    case DIVIDE:
    case CLOSEBY:
    case END:
      ValuableToken t;
      t.token = E;
    	return automaton->reduce(3, t, 3);
    default: return false; // Error !
  }
  return false;
}

