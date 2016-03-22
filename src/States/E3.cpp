//
//  LutinLangInterperter
//  E3.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E3.h"
#include "../Tokens.h"

E3::E3() : State() { }

bool E3::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case SEP:
    case END:
      ValuableToken t;
      t.token = LV;
      return automaton->reduce(1, t, 1);
    default: return false; // Error !
  }
  return false;
}
