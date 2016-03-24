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


bool Ecrire::execute(Declrs & variables,bool silent)
{
    /*string nom = this->variable -> get_nom();
    double valeur;
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        valeur = this->variable->Evaluation(variables);
        cout << valeur <<endl;
        return true;
    }
    else{ // Error Variable non déclarée
        return false;
    }*/
	bool error;
	double value;
	error = expression -> Evaluation(&value,variables);
	if(!silent) if(error) cout << value <<endl;
	return error;
}

void Ecrire::print(ostream& os) const
{
	//cout << "ecrire ";
	//variable->print();
	//cout <<";";
	os << "ecrire " << *expression << ";" ;
}

/*bool Ecrire::optimize_back(Instruction** inst,Declrs & variables) 
{
	bool error;
	double value;
	error = expression -> Evaluation(&value,variables);
	if(!error) 
	{
		return false;
	}else
	{
		Valeur* vl = new Valeur(value);
		*inst = new Ecrire(vl);
		return true;
	}
}*/

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




