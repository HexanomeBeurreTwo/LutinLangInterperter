//
//  LutinLangInterperter
//  E28.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E28.h"

E28::E28() : State() { }

bool E28::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

