#include "Lire.h"
#include "DeclarationVariable.h"

Lire::~Lire()
{
    delete variable;
}


bool Lire::execute(Declrs & variables)
{
    string nom = variable -> get_nom();
    double valeur;
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        if(DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(variables[nom]) )
        {
            cin >> valeur;
            v->affect(valeur);
            return true;
        }else // impossible d'affecter a un const
        {
            return false;
        }

    }
    else{ // Error Variable non déclarée
        return false;
    }
}


bool Lire::analyse(Declrs & variables)
{
    string nom = variable -> get_nom();
    
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        if(DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(variables[nom]) )
        {
            v->set_used();
            v->set_initialized();
            return true;
        }else // impossible d'affecter a un const
        {
			cerr << "Pas possible d'affecter une conse " << nom << endl;
            return false;
        }
    }
    else{ // Error Variable non déclarée
       cerr << "la variable " << nom << " n'a pas ete declaree." << endl;

		Declaration * dec = new DeclarationVariable(nom);
		dec->set_undeclared();
		dec->set_used();
		variables[nom] = dec ;
        dec->set_initialized();
        return true;
    }
}

void Lire::print(ostream& os) const
{
	/*cout << "lire ";
	variable->print();
	cout <<";";*/
	os  << "lire " << (*variable) << ";" ;

}

void Lire::get_expression(ostream& os)
{
    variable->print(os);
}

bool Lire::optimize(Instruction** inst,Declrs & variables)
{
		Variable* var = new Variable(variable->get_nom());
		*inst = new Lire(var);
		return true;
}
