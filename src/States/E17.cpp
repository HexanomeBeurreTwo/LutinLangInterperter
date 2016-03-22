//
//  LutinLangInterperter
//  E17.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E17.h"

E17::E17() : State() { }

bool E17::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
    case VAR:
    case CONST:
    case READ:
    case WRITE:
    case END_OF_FILE:
      ValuableToken t;
      t.token = PD;
      return automaton->reduce(3, t, 3);
      break;
    default: return false; // Error !
  }
  return false;
}
