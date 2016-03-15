//
//  LutinLangInterperter
//  E8.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E8.h"

E8::E8() : State() { }

bool E8::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case SEP:
    case END:
      ValuableToken t;
      t.token = LD;
      return automaton->reduce(3, t, 3);
      break;
    default: return false; // Error !
  }
  return false;
}
