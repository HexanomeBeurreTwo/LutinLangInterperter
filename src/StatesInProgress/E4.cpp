//
//  LutinLangInterperter
//  E4.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E4.h"
#include "E7.h"

E4::E4() : State() { }

bool E4::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case SEP:
      return automaton->shift(s, new E7());
    case END:
      valuableToken t;
      t.token = LD;
      return automaton->reduce(2, t, 2);
    default: return false; // Error !
  }
  return false;
}
