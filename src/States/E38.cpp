//
//  LutinLangInterperter
//  E38.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include E38.h

E38::E38() : State() { }

bool E38::transition(Automaton *automaton, Symbol *t) {
  switch(*t) {
    case XXX:
      // Do();
      break;
  }
  return false;
}

