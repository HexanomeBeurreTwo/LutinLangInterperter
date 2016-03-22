//
//  LutinLangInterperter
//  E15.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E15.h"
#include "Tokens.h"

E15::E15() : State() { }

bool E15::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case SEP:
    case END:
	  ValuableToken t;
	  t.token = D;
      return automaton->reduce(3, t, 3);
      break;
    default: return false; // Error !
  }
  return false;
}
