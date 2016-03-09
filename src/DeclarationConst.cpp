#include "DeclarationConst.h"

#include <iostream>
using namespace std;

void DeclarationConst::print()
{
    cout << "const " << nom << "=" << valeur <<";"<<endl;
}
