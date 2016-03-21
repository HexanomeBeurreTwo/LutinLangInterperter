//
//  LutinLangInterperter
//  E38.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E38.h"
#include "E29.h"
#include "E31.h"
#include "E32.h"
#include "E33.h"
#include "E39.h"
  
E38::E38() : State() { }

bool E38::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case PLUS:
     	return automaton->shift(s, new E29());
		break;
    case MINUS:
    	return automaton->shift(s, new E31());
    case MULT:
    	return automaton->shift(s, new E32());
    case DIVIDE:
    	return automaton->shift(s, new E33());
	case CLOSEBY:
    	return automaton->shift(s, new E39());
    default: return false; // Error !
  }
  return false;
}

