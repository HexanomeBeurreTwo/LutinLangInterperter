//
//  LutinLangInterperter
//  E27.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E27.h"
#include "E37.h"
#include "E40.h"
#include "E28.h"

E27::E27() : State() { }

bool E27::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case OPENBY:
    	return automaton->shift(s, new E37());
    case VAL:
    	return automaton->shift(s, new E40());
    case E:
      return automaton->shift(s, new E28());
    default: return false; // Error !
  }
  return false;
}

