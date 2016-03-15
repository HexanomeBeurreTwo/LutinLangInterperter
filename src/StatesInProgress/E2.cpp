//
//  LutinLangInterperter
//  E2.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E2.h"
#include "E3.h"
#include "E4.h"

E2::E2() : State() { }

bool E2::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
      return automaton->shift(s, new E3());
    case LV:
      return automaton->shift(s, new E4());
    default: return false; // Error !
  }
  return false;
}
