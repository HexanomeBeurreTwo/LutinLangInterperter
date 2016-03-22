//
//  LutinLangInterperter
//  E14.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E14.h"
#include "E15.h"
E14::E14() : State() { }

bool E14::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case VAL:
      return automaton->shift(s, new E15());
    default: return false; // Error !
  }
  return false;
}
