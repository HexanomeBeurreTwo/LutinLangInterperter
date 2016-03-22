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
#include "Symbol.h"
#include "Expression.h"

using namespace std;


bool Affectation::execute(Declrs & variables)
{
    string nom = variable -> get_nom();
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        if(DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(variables[nom]))
        {
			bool error;
			double value;
			error = this->expression->Evaluation(&value,variables);
            if (error) v->affect(value);
            return error;
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

void Affectation::print(ostream& os) const
{
	/*variable->print();
	cout << " := ";
	expression -> print();
	cout << ";";*/
    os << (*variable) << " := " << (*expression) << ";" ;
}


bool Affectation::optimize(Instruction** inst,const Declrs & variables) 
{
	bool error;
	double value;
	error = expression -> Evaluation(&value,variables);
	if(!error) 
	{
		return false;
	}else
	{
		Variable* var = new Variable(variable->get_nom());
		Valeur* valeur = new Valeur(value);
		*inst = new Affectation(valeur,var);
		return true;
	}
}
