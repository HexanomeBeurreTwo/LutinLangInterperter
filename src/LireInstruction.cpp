#include "LireInstruction.h"
#include "DeclarationVariable.h"

LireInstruction::~LireInstruction()
{
    //delete variable;
}

bool LireInstruction::reads(Declrs & variables)
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

void LireInstruction::print()
{
	cout << "Read ";
	variable->print();
	cout <<" ";
}
