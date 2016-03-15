//
//  LutinLangInterperter
//  E12.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E12.h"

E12::E12() : State() { }

bool E12::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case SEP:
    case END:
    ValuableToken t;
    t.token = LC
      return automaton->reduce(3, t, 3);
    default: return false; // Error !
  }
  return false;
}
