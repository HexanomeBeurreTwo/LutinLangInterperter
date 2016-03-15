//
//  LutinLangInterperter
//  E9.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E9.h"

E9::E9() : State() { }

bool E9::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case SEP:
    case END:
      automaton.reduce(1, *s, new E10());
      break;
  }
  return false;
}
