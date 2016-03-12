//
//  LutinLangInterperter
//  Affectationol.cpp
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include <iostream>
#include "Affectation.h"
#include "Declaration.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"

using namespace std;


bool Affectation::execute(Declrs & variables)
{
    string nom = variable -> get_nom();
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        if(DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(variables[nom]))
        {
            v->affect(this->expression->Evaluation(variables));
            return true;
        }
        return false; // Error : affectaion de const !
    }
    else{ // Error Variable non déclarée
        return false;
    }

}

Affectation::~Affectation()
{
    delete expression;
    delete variable;
}

void Affectation::print()
{
	variable->print();
	cout << " := ";
	expression -> print();
	cout << ";";

}
