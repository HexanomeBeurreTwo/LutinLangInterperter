//
//  LutinLangInterperter
//  E30.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E30.h"
#include "E30.h"
#include "E32.h"
#include "E33.h"

E30::E30() : State() { }

bool E30::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case PLUS:
    case MINUS:
    case CLOSEBY:
    case END:
      ValuableToken t;
      t.token = E;
    	return automaton->reduce(3, t, 3);
    case MULT:
    	return automaton->shift(s, new E32());
    case DIVIDE:
    	return automaton->shift(s, new E33());
    default: return false; // Error !
  }
  return false;
}

