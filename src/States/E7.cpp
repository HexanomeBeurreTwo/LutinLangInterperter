//
//  LutinLangInterperter
//  E7.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E7.h"

E7::E7() : State() { }

bool E7::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case ID:
      automaton.shift(*s, new E8());
      break;
  }
  return false;
}
