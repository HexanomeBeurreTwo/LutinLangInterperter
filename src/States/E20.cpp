//
//  LutinLangInterperter
//  E20.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E20.h"

E20::E20() : State() { }

bool E20::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
    case READ:
    case WRITE:
    case END_OF_FILE:
      ValuableToken t;
      t.token = PI;
      return automaton->reduce(2, t, 3);
    default: return false; // Error !
  }
  return false;
}

