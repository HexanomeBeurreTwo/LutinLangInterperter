//
//  LutinLangInterperter
//  E18.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E18.h"

E18::E18() : State() { }

bool E18::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case ID:
      // Do();
      break;
  }
  return false;
}
