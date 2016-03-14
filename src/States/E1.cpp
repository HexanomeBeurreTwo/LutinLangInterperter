//
//  LutinLangInterperter
//  E1.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Tokens.h"

#include "E1.h"

E1::E1() : State() { }

bool E1::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
    case READ:
    case WRITE:
    case END_OF_FILE:
      //automaton->reduce(0, s, new E18(),?);
      break;
    case VAR:
      //automaton.shift(s, new E2());
      break;
    case CONST:
      //automaton.shift(s, new E5());
      break;

    default: break; // Error !
  }
  return false;
}
