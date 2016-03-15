//
//  LutinLangInterperter
//  E28.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E28.h"

E28::E28() : State() { }

bool E28::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case PLUS:
    	automaton.shift(*s, new E29());
      break;
    case MINUS:
    	automaton.shift(*s, new E31());
      break;
    case MULT:
    	automaton.shift(*s, new E32());
      break;
    case DIVIDE:
    	automaton.shift(*s, new E33());
      break;
    case END:
    	automaton.reduce(2, *s, new E19());
      break;
  }
  return false;
}

