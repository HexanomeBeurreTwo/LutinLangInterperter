//
//  LutinLangInterperter
//  E30.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E30.h"

E30::E30() : State() { }

bool E30::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case PLUS:
    case MINUS:
    case CLOSEBY:
    case END:
    	automaton.reduce(1, *s, new E30());
      break;
    case MULT:
    	automaton.shift(*s, new E32());
      break;
    case DIVIDE:
    	automaton.shift(*s, new E33());
      break;
  }
  return false;
}

