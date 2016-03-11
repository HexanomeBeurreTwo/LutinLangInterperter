//
//  LutinLangInterperter
//  E11.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E11.h"

E11::E11() : State() { }

bool E11::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case ID:
      automaton.shift(*s, new E13());
      break;
  }
  return false;
}