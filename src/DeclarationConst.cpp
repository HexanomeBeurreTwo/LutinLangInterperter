#include "DeclarationConst.h"

#include <iostream>
using namespace std;

void DeclarationConst::print(ostream& os) const
{
    os << "const " << nom << " = " << valeur <<";"<<endl;
}
