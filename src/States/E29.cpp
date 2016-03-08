//
//  LutinLangInterperter
//  E29.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E29.h"

E29::E29() : State() { }

bool E29::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

