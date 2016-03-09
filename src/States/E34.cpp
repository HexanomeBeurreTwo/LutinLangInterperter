//
//  LutinLangInterperter
//  E34.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E34.h"

E34::E34() : State() { }

bool E34::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case MULT:
    	automaton.shift(*s, new E32());
      break;
    case DIVIDE:
    	automaton.shift(*s, new E33());
      break;
    case PLUS:
    case MINUS:
    case END:
    	automaton.reduce(1,*s,new E34());
  	  break;
  }
  return false;
}

