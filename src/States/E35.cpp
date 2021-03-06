//
//  LutinLangInterperter
//  E35.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E35.h"

E35::E35() : State() { }

bool E35::transition(Automaton *automaton, ValuableToken s) {
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
      break;
    default: return false; // Error !
  }
  return false;
}

