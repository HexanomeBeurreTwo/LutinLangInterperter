//
//  LutinLangInterperter
//  E5.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E5.h"
#include "E9.h"
#include "E10.h"
#include "E13.h"

E5::E5() : State() { }

bool E5::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case ID:
      return automaton->shift(s, new E13());
      break;
    case LC:
      return automaton->shift(s, new E10());
      break;
    case D:
      return automaton->shift(s, new E9());
      break;
    default: 
		return false; // Error !
  }
  return false;
}
