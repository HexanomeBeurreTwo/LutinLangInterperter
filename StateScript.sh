#!/bin/bash

for i in {0..40}
do
  # Generate the .h
  echo "//
//  LutinLangInterperter
//  E$i.h
//
//  Created by H4115 on 01/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef SRC_STATES_E${i}_H_
#define SRC_STATES_E${i}_H_

#include \"../State.h\"
#include \"../ASTNode.h\"
#include \"../Automaton.h\"

class E$i : public State {
 public:
    E$i();
    bool transition(Automaton *automaton, ASTNode *t);
    inline int getStateNumber(){return $i;}
};

#endif  // SRC_STATES_E${i}_H_
" >> ./State/E$i.h

echo "//
//  LutinLangInterperter
//  E$i.h
//
//  Created by H4115 on 01/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include \"../State.h\"
#include \"../TokenType.h\"
#include \"../ASTDeclarationBlockNode.h\"

#include "E$i.h"


E$i::E$i() : State() { }

bool E$i::transition(Automaton *automaton, ASTNode *t) {

}
" >> ./State/E$i.cpp

done
