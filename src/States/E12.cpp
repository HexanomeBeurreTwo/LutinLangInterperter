//
//  LutinLangInterperter
//  E12.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E12.h"

E12::E12() : State() { }

bool E12::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case SEP:
    case END:
      automaton.reduce(3, *s, new E10());
      break;
  }
  return false;
}
