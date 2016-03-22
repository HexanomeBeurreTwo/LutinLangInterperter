#include "Ecrire.h"
#include "DeclarationVariable.h"
#include "Expression.h"
#include "Symbol.h"

//Ecrire::Ecrire(Expression* exp):
//Instruction(WRITE),expression(exp){};


Ecrire::~Ecrire(){
	delete expression;
}


bool Ecrire::execute(Declrs & variables)
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
	if(error) cout << value <<endl;
	return error;
}

void Ecrire::print(ostream& os) const
{
	//cout << "ecrire ";
	//variable->print();
	//cout <<";";
	os << "ecrire " << *expression << ";" ;
}

bool Ecrire::optimize(Instruction** inst,const Declrs & variables) 
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
}


