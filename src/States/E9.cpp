//
//  LutinLangInterperter
//  E9.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E9.h"

E9::E9() : State() { }

bool E9::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case SEP:
    case END:
      ValuableToken t;
      t.token = LC;
      return automaton->reduce(1, t, 1);
      break;
    default: return false; // Error !
  }
  return false;
}
