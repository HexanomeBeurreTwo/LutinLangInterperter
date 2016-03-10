//
//  LutinLangInterperter
//  E3.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E3.h"

E3::E3() : State() { }

bool E3::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case SEP:
    case END:
      automaton.reduce(1, *s, new E4());
      break;
  }
  return false;
}
