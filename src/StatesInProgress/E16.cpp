//
//  LutinLangInterperter
//  E16.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E16.h"
#include "E17.h"
E16::E16() : State() { }

bool E16::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case END:
      automaton->shift(s, new E17());
      break;
    default: return false; // Error !
  }
  return false;
}
