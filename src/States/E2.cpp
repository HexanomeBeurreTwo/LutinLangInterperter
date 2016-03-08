//
//  LutinLangInterperter
//  E2.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E2.h"

E2::E2() : State() { }

bool E2::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case ID:
      automaton.shift(*s, new E3());
      break;
  }
  return false;
}
