//
//  LutinLangInterperter
//  E13.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "E13.h"
#include "E14.h"

E13::E13() : State() { }

bool E13::transition(Automaton *automaton, ValuableToken s) {
  switch(s.token) {
    case EQUAL:
      return automaton->shift(s, new E14());
    default: 
      cerr << "Erreur " << automaton->getLexer()->getCursor() << " Symbole attendu : := "<< endl;
      return false; // Error !
     
      
  }
  return false;
}
