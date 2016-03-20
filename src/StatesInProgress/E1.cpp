//
//  LutinLangInterperter
//  E1.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Automaton.h"
#include "../Tokens.h"

#include "E1.h"
#include "E2.h"
#include "E5.h"
#include "E16.h"
#include "E18.h"

E1::E1() : State() { }

bool E1::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
    case READ:
    case WRITE:
    case END_OF_FILE:
      ValuableToken t;
      t.token = PI;
      return automaton->reduce(0, t, 0);
    case VAR:
		return automaton->shift(s, new E2()); 
    case CONST:
		return automaton->shift(s, new E5()); 
    case PI:
		return automaton->shift(s, new E18());
    case LD:
		return automaton->shift(s, new E16());
    default: break; // Error !
  }
  return false;
}
