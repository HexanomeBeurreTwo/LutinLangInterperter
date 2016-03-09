#include "PartieDeclarative.h"
#include <iostream>

using namespace std;

bool PartieDeclarative::add_declaration(Declaration *inst)
{
    string nom;
    Declrs::const_iterator var = variables.find(nom);
    if (var!=variables.end())  //if existe
    {
        variables[inst->get_nom()] = inst;
        return true;
    }else{
        // Erreur variable déja prise !
        return false;
    }
}

void PartieDeclarative::print()
{
    //  // show content of variables
  for (Declrs::iterator it=variables.begin(); it!=variables.end(); ++it)
    //std::cout << it->first << " => " << it->second << '\n';
    (it->second)->print();

}
