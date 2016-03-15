//
//  LutinLangInterperter
//  E28.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E28.h"
#include "E29.h"
#include "E31.h"
#include "E32.h"
#include "E33.h"

E28::E28() : State() { }

bool E28::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case PLUS:
    	return automaton->shift(s, new E29());
    case MINUS:
    	return automaton->shift(s, new E31());
    case MULT:
    	return automaton->shift(s, new E32());
    case DIVIDE:
    	return automaton->shift(s, new E33());
    case END:
      ValuableToken t;
      t.token = LI;
    	return automaton->reduce(2, t, 2);
    default: return false; // Error !
  }
  return false;
}

