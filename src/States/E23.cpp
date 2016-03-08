//
//  LutinLangInterperter
//  E23.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include E23.h

E23::E23() : State() { }

bool E23::transition(Automaton *automaton, Symbol *t) {
  switch(*t) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

