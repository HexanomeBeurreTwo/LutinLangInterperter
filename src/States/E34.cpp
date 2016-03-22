//
//  LutinLangInterperter
//  E34.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E34.h"
#include "E32.h"
#include "E33.h"

E34::E34() : State() { }

bool E34::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case MULT:
    	return automaton->shift(s, new E32());
    case DIVIDE:
    	return automaton->shift(s, new E33());
    case PLUS:
    case MINUS:
    case CLOSEBY:
    case END:
      ValuableToken t;
      t.token = E;
    	return automaton->reduce(3,t,3);
    default: return false; // Error !
  }
  return false;
}

