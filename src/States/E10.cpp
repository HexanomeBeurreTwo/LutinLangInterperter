//
//  LutinLangInterperter
//  E10.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E10.h"

E10::E10() : State() { }

bool E10::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case SEP:
      automaton.shift(*s, new E11());
      break;
    case END:
      automaton.reduce(2, *s, new E16());
      break;
  }
  return false;
}
