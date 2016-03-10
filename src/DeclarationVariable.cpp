#include "DeclarationVariable.h"

#include <iostream>
using namespace std;

void DeclarationVariable:: affect(double val)
{
    this->valeur = val;
}

void DeclarationVariable::print()
{
    cout << "var " << nom <<";"<<endl;
}
