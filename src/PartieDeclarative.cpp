#include "PartieDeclarative.h"
#include "Declaration.h"
#include "DeclarationVariable.h"
#include "DeclarationConst.h"
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
		cerr << "la variable "<<nom<<" est deja declaree" << endl;
        return false;
    }
}

 Declrs& PartieDeclarative::get_variables()
 {
     return this->variables;
 }

void PartieDeclarative::print(ostream& os) const
{

  for (Declrs::const_iterator it=variables.begin(); it!=variables.end(); ++it)
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
			
		} else if(DeclarationConst* v = dynamic_cast<DeclarationConst*>(it->second))
		{	
			variables[v->get_nom()] = (new DeclarationConst(v->get_nom(),v->get_valeur()));
		}
		
    } 
	
 }
 
 void PartieDeclarative::optimize()
 {
	for (Declrs::const_iterator it=variables.begin(); it!=variables.end(); ++it)
    {
        if(DeclarationConst* v = dynamic_cast<DeclarationConst*>(it->second))
        {
			variables.erase(v->get_nom());
		}
		
    } 
 }
 
 void PartieDeclarative::check_uninitialized_var()
 {
	bool founded = false;
	
	string uninitialized_var = "variable non affectee : ";
	
	for (Declrs::const_iterator it=variables.begin(); it!=variables.end(); ++it)
    {
        if( DeclarationVariable* v = dynamic_cast<DeclarationVariable*>(it->second)  )
		if (!v->is_initialized())
        {
			//uninitialized_var += v->get_nom() + " ";
			uninitialized_var += v->get_nom() ;
			founded = true;
		}
		
    } 
	if(founded)
		cerr << uninitialized_var << endl;
 }
 
  
 void PartieDeclarative::check_unused_vars()
 {
	bool founded = false;
	//string uninitialized_var = "WRN : unused vars : ";
	string uninitialized_var = "variable non utilisee : ";
	for (Declrs::const_iterator it=variables.begin(); it!=variables.end(); ++it)
    {
        
		if (!(it->second)->is_used())
        {
			uninitialized_var += (it->second)->get_nom() + " ";
			founded = true;
		}
    } 
	if(founded)
		cerr << uninitialized_var << endl;
 }

 
 void PartieDeclarative::check_undeclared()
 {
   //bool founded = false;
	//string uninitialized_var = "ERR : undeclared vars : ";
	string uninitialized_var = "la variable ";
	for (Declrs::const_iterator it=variables.begin(); it!=variables.end(); ++it)
    {
        
		if (!(it->second)->is_declared())
        {
			uninitialized_var += (it->second)->get_nom() + " ";
			//founded = true;
		}
		
    } 
	// if(founded)
		// cerr << uninitialized_var+"n'a pas ete declaree." << endl;
 }
