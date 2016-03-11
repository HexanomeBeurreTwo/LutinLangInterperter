//
//  LutinLangInterperter
//  E16.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "../State.h"
#include "../Symbol.h"

#include "E16.h"

E16::E16() : State() { }

bool E16::transition(Automaton *automaton, Symbol *s) {
  switch(*s) {
    case END:
      automaton->shift(*s, new E17());
      break;
  }
  return false;
}