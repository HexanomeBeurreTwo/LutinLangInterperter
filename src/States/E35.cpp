//
//  LutinLangInterperter
//  E35.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E35.h"

E35::E35() : State() { }

bool E35::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

