//
//  LutinLangInterperter
//  E7.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E7.h"
#include "E8.h"
E7::E7() : State() { }

bool E7::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
      return automaton->shift(s, new E8());
      break;
    default: return false; // Error !
  }
  return false;
}
