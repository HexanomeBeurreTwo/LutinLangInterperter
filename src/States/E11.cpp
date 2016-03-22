//
//  LutinLangInterperter
//  E11.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E11.h"
#include "E12.h"
#include "E13.h"

E11::E11() : State() { }

bool E11::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
      return automaton->shift(s, new E13());      
    case D:
      return automaton->shift(s, new E12());
      default: return false; // Error !
     }
  return false;
}
