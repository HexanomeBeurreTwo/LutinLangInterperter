//
//  LutinLangInterperter
//  E18.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E18.h"
#include "E19.h"
#include "E21.h"
#include "E25.h"
#include "E27.h"

E18::E18() : State() { }

bool E18::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
      return automaton->shift(s, new E21());
    case READ:
      return automaton->shift(s, new E25());
    case WRITE:
      return automaton->shift(s, new E27());
    case ENDFILE:
      return ////////////////////////////////////////////////////// on est arrivé à la fin du programme
   	case LI:
   	  return automaton->shift(s, new E19());
    default: return false; // Error !
  }
  return false;
}
