//
//  LutinLangInterperter
//  E34.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include E34.h

E34::E34() : State() { }

bool E34::transition(Automaton *automaton, Symbol *t) {
  switch(*t) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

