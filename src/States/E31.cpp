//
//  LutinLangInterperter
//  E31.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E31.h"
#include "E24.h"
#include "E34.h"
#include "E37.h"
#include "E40.h"

E31::E31() : State() { }

bool E31::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case OPENBY:
    	return automaton->shift(s, new E37());
    case ID:
    	return automaton->shift(s, new E24());
    case VAL:
    	return automaton->shift(s, new E40());
    case E:
      return automaton->shift(s, new E34());
    default: return false; // Error !
  }
  return false;
}

