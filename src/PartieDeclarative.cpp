#include "PartieDeclarative.h"
#include "Declaration.h"
#include "DeclarationVariable.h"
#include "Symbol.h"
#include <iostream>

using namespace std;

bool PartieDeclarative::add_declaration(Declaration *inst)
{
    string nom = inst->get_nom();
    Declrs::const_iterator var = variables.find(nom);
    if (var==variables.end())  // variable non utilisé -> ok
    {
        variables[inst->get_nom()] = inst;
        return true;
    }else{
        return false;
    }
}

 Declrs& PartieDeclarative::get_variables()
 {
     return this->variables;
 }

void PartieDeclarative::print(ostream& os) const
{
    //  // show content of variables
  for (Declrs::const_iterator it=variables.begin(); it!=variables.end(); ++it)
    //std::cout << it->first << " => " << it->second << '\n';
    //(it->second)->print();
    os << *(it->second) ;

}


PartieDeclarative::~PartieDeclarative()
{
     for (Declrs::iterator it=variables.begin(); it!=variables.end(); ++it)
     {
        delete (it->second);
     }

}

void PartieDeclarative::clone_vars(const PartieDeclarative& src)
 {
	for (Declrs::const_iterator it=src.variables.begin(); it!=src.variables.end(); ++it)
    {
        if(DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(it->second))
        {
			variables[v->get_nom()] = (new DeclarationVariable(v->get_nom()));
		}
    } 
	
 }

