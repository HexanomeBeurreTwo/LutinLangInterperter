//
//  LutinLangInterperter
//  E25.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E25.h"
#include "E26.h"

E25::E25() : State() { }

bool E25::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
    	return automaton->shift(s, new E26());
    default: return false; // Error !
  }
  return false;
}

