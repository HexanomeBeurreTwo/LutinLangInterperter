//
//  LutinLangInterperter
//  E24.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E24.h"

E24::E24() : State() { }

bool E24::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case PLUS:
    case MINUS:
    case MULT:
    case DIVIDE:
    case CLOSEBY:
    case END:
      ValuableToken t;
      t.token = E;
      return automaton->reduce(1, t, 1);
    default: return false; // Error !
  }
  return false;
}

