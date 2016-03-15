#include "Ecrire.h"
#include "DeclarationVariable.h"
#include "Expression.h"
#include "Symbol.h"


Ecrire::~Ecrire()
{
    delete variable;
}


bool Ecrire::execute(Declrs & variables)
{
    string nom = this->variable -> get_nom();
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
    }

}

void Ecrire::print(ostream& os) const
{
	//cout << "ecrire ";
	//variable->print();
	//cout <<";";
	os << "ecirre " << *variable << ";" ;
}
