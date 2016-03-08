//
//  LutinLangInterperter
//  E5.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E5.h"

E5::E5() : State() { }

bool E5::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case ID:
      automaton.shift(*s, new E13());
      break;
  }
  return false;
}
