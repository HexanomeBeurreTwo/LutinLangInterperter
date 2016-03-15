//
//  LutinLangInterperter
//  E33.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E33.h"

E33::E33() : State() { }

bool E33::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case OPENBY:
    	automaton.shift(*s, new E37());
      break;
    case ID:
    	automaton.shift(*s, new E24());
      break;
    case VAL:
    	automaton.shift(*s, new E40());
      break;
  }
  return false;
}

