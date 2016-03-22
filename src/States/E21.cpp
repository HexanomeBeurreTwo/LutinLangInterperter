//
//  LutinLangInterperter
//  E21.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//



#include "E21.h"
#include "E22.h"

E21::E21() : State() { }

bool E21::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case AFFECT:
      return automaton->shift(s, new E22());
    default: return false; // Error !
  }
  return false;
}

