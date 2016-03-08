//
//  LutinLangInterperter
//  E8.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E8.h"

E8::E8() : State() { }

bool E8::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case SEP:
    case END:
      automaton.reduce(3, *s, new E4());
      break;
  }
  return false;
}
