//
//  LutinLangInterperter
//  E17.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E17.h"

E17::E17() : State() { }

bool E17::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case ID:
    case VAR:
    case CONST:
    case READ:
    case WRITE:
    case ENDFILE:
      automaton.reduce(3, *s, new E1());
      break;
  }
  return false;
}