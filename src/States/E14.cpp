//
//  LutinLangInterperter
//  E14.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E14.h"

E14::E14() : State() { }

bool E14::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case VAL:
      automaton.shift(*s, new E15());
      break;
  }
  return false;
}
