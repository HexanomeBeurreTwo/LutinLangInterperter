#include "DeclarationVariable.h"

#include <iostream>
using namespace std;

void DeclarationVariable:: affect(double val)
{
    this->valeur = val;
    this-> initialized = true;
}

void DeclarationVariable::print(ostream& os) const
{
    os << "var " << nom <<";"<<endl;
}
