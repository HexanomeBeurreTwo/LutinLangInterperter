#include "Lire.h"
#include "DeclarationVariable.h"

Lire::~Lire()
{
    delete variable;
}

bool Lire::execute(Declrs & variables,bool silent)
{
    string nom = variable -> get_nom();
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        if((DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(variables[nom]) && !silent)
        {
            double valeur;
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

void Lire::print(ostream& os) const
{
	/*cout << "lire ";
	variable->print();
	cout <<";";*/
	os  << "lire " << (*variable) << ";" ;

}


bool Lire::optimize(Instruction** inst,Declrs & variables)
{
		Variable* var = new Variable(variable->get_nom());
		*inst = new Lire(var);
		return true;
}
