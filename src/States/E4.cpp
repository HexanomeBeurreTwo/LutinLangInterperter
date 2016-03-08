//
//  LutinLangInterperter
//  E4.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E4.h"

E4::E4() : State() { }

bool E4::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case SEP:
      automaton.shift(*s, new E7());
      break;
    case END:
      automaton.shift(2, *s, new E16());
      break;
  }
  return false;
}
