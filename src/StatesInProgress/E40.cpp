//
//  LutinLangInterperter
//  E40.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E40.h"

E40::E40() : State() { }

bool E40::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case PLUS:
    case MINUS:
    case MULT:
    case DIVIDE:
    case CLOSEBY:
    case END:
      ValuableToken t;
      t.token = E;
    	return automaton->reduce(1, t, 1);
    default: return false; // Error !
  }
  return false;
}

