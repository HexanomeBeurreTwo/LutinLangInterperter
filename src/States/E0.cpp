//
//  LutinLangInterperter
//  E0.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Automaton.h"
#include "../Tokens.h"

#include "E0.h"
#include "E1.h"

E0::E0() : State() { }

bool E0::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
    case VAR:
    case CONST:
    case READ:
    case WRITE:
		ValuableToken t;
		t.token = PD;
		return automaton->reduce(0, t, 0);
		break;
    case END_OF_FILE:
        //ValuableToken t;
        t.token = PD;
		return automaton->reduce(0, t, 0);
		break;
	case PD :
		return automaton->shift(s, new E1()); 
		break;
    default: return false; // Error !
  }
  return false;
}
