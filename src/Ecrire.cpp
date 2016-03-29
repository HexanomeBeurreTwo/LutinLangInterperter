#include "Ecrire.h"
#include "DeclarationVariable.h"
#include "Expression.h"
#include "Symbol.h"
#include <iostream>

using namespace std;
//Ecrire::Ecrire(Expression* exp):
//Instruction(WRITE),expression(exp){};


Ecrire::~Ecrire(){
	delete expression;
}


bool Ecrire::execute(Declrs & variables)
{
	bool error;
	double value;
	error = expression -> Evaluation(&value,variables);
	if(error) 
		cout << value <<endl;
	return error;
}

bool Ecrire::analyse(Declrs & variables)
{
	bool error;
	double value;
	error = expression -> analyse(&value,variables);
	return error;	
}


void Ecrire::print(ostream& os) const
{
	os << "ecrire " << *expression << ";" ;
}

void Ecrire::get_expression(ostream& os)
{
    expression->print(os);
}

bool Ecrire::optimize(Instruction** inst,Declrs & variables) 
{
	bool error = true;
	double value;
	Expression* expr_to_write,* expOpz ;
	
	expOpz = expression -> get_ptimized_expression(variables);
	
	//(expOpz) -> print(cout);
	//cout << endl;
	
	error = expOpz -> Evaluation(&value,variables);
	
	if(!error) 
	{
		expr_to_write = expOpz;
		
	}else{ //typedef map<string,Declaration*> Declrs;
		expr_to_write = new Valeur(value);
		
	}
	
	*inst = new Ecrire(expr_to_write);
	return true;
}




