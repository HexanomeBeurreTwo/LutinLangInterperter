//
//  LutinLangInterperter
//  E19.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E19.h"
#include "E20.h"

E19::E19() : State() { }

bool E19::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case END:
      return automaton->shift(s, new E20());
    default: return false; // Error !
  }
  return false;
}

