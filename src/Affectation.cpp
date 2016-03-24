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
            if (error) 
			{
				v->affect(value);
				v->set_used();
			}
            return error;
        }
        return false; // Error : affectaion de const !
    }
    else{ // Error Variable non déclarée
        return false;
    }

}

bool Affectation::analyse(Declrs & variables)
{
    string nom = variable -> get_nom();
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        if(DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(variables[nom]))
        {
			bool error;
			double value;
			error = this->expression->analyse(&value,variables);
			//v->set_used();
			v->set_initialized();
            return error;
        }
        cerr << "Pas possible d'affecter une const : " << nom << endl;
        return false; // Error : affectaion de const !
    }
    else{ // var non declarée
		Declaration * dec = new DeclarationVariable(nom);
		dec->set_undeclared();
		dec->set_used();
		dec->set_initialized();
		variables[nom] = dec ;

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

    os << (*variable) << " := " << (*expression) << ";" ;
}




bool Affectation::optimize(Instruction** inst,Declrs & variables) 
{
	bool error;
	double value;
	Expression* expr_to_affect;
	
	string nom = variable->get_nom();	
	Expression* expOpz = expression -> get_ptimized_expression(variables);
	
	error = expOpz -> Evaluation(&value,variables);
	
	if(!error) 
	{
		expr_to_affect = expOpz;
		
	}else{ //typedef map<string,Declaration*> Declrs;
		expr_to_affect = new Valeur(value);
		if(DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(variables[nom]))
        {
			v->affect(value);
		}	
	}
	
	Variable* var = new Variable(nom);
	*inst = new Affectation(expr_to_affect,var);
	
	return true;
	
}
