#include "EcrireInstruction.h"


EcrireInstruction::~EcrireInstruction()
{
    //delete variable;
}


bool EcrireInstruction::writes(Declrs & variables)
{
    string nom = this->variable -> get_nom();
    double valeur;
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        valeur = this->variable->Evaluation(variables);
        cout << valeur;
        return true;
    }
    else{ // Error Variable non déclarée
        return false;
    }

}

void EcrireInstruction::print()
{
	cout << "Write ";
	variable->print();
	cout <<"\n";
}
