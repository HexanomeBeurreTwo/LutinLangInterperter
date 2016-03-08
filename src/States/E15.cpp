//
//  LutinLangInterperter
//  E15.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E15.h"

E15::E15() : State() { }

bool E15::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case SEP:
    case END:
      automaton.reduce(3, *s, new E12());
      break;
  }
  return false;
}
