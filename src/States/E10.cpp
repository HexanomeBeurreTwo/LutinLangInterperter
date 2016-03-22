//
//
//  LutinLangInterperter
//  E10.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E10.h"
#include "E11.h"

E10::E10() : State() { }

bool E10::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case SEP:
      return automaton->shift(s, new E11());
      break;
    case END:
      ValuableToken t;
      t.token = LD;
      return automaton->reduce(2, t, 2);
      break;
    default: return false; // Error !
  }
  return false;
}
