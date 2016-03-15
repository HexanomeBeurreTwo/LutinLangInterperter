#include "DeclarationConst.h"

#include <iostream>
using namespace std;

void DeclarationConst::print(ostream& os) const
{
    //cout << "const " << nom << " = " << valeur <<";"<<endl;
    os << "const " << nom << " = " << valeur <<";"<<endl;
}
