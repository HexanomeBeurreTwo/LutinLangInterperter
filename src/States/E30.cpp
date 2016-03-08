//
//  LutinLangInterperter
//  E30.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include E30.h

E30::E30() : State() { }

bool E30::transition(Automaton *automaton, Symbol *t) {
  switch(*t) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

