//
//  LutinLangInterperter
//  E36.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E36.h"

E36::E36() : State() { }

bool E36::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

