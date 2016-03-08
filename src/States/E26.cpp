//
//  LutinLangInterperter
//  E26.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E26.h"

E26::E26() : State() { }

bool E26::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

