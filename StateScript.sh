#!/bin/bash

for i in {0..40}
do
  # Generate the .h
  echo "//
//  LutinLangInterperter
//  E$i.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef STATE_E${i}_H_
#define STATE_E${i}_H_

#include \"../State.h\"
#include \"../Symbol.h\"
#include \"../Automaton.h\"

class E$i : public State {
 public:
    E$i();
    bool transition(Automaton *automaton, Symbol * t);
    inline int getStateNumber(){return $i;}
};

#endif  // STATE_E${i}_H_
" >> ./src/States/E$i.h

echo "//
//  LutinLangInterperter
//  E$i.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include \"../State.h\"
#include \"../Symbol.h\"

#include "E$i.h"

E$i::E$i() : State() { }

bool E$i::transition(Automaton *automaton, Symbol *t) {
  switch(*t) {
    case XXX:
      // Do();
      break;
  }
  return false;
}
" >> ./src/States/E$i.cpp

done
