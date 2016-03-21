#include "Expression.h"
#include<iostream>
#include "Declaration.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "Symbol.h"

using namespace std;


bool Valeur::Evaluation(double *res,const Declrs & variables) {
   *res = this->valeur;
   return true;
}


bool Variable::Evaluation(double *res,const Declrs & variables) {
   Declrs::const_iterator var = variables.find(nom);
   if (var!=variables.end()) {
      *res = (var->second)->get_valeur();
	  return true;
   } else {
      return false;
   }
}

OperateurBinaire::~OperateurBinaire() {
   delete gauche;
   delete droite;
}

bool OperateurBinaire::Evaluation(double *res,const Declrs & variables) {
   double valg,vald;
   if( !gauche->Evaluation(&valg,variables) ||
	   !droite->Evaluation(&vald,variables) )
   {
		return false;
   }
   *res = operation(valg,vald);
   return true;
}

bool Parentese::Evaluation(double *res,const Declrs & variables) {
   return expression->Evaluation(res,variables);
}


double OperateurPlus::operation(double g, double d) {
   return g+d;
}


double OperateurMoins::operation(double g, double d) {
   return g-d;
}


double OperateurDiv::operation(double g, double d) {
   return g/d;
}


double OperateurMul::operation(double g, double d) {
   return g*d;
}

void Variable::print(ostream& os) const{
    os <<""<<nom<<"";
}

void Valeur::print(ostream& os) const{
    os <<""<<valeur<<"";
}

void Parentese::print(ostream& os) const{
    /*cout << "(" ;
    expression->print();
    cout << ")";*/
    os << "(" << (*expression) << ")" ;

}
void OperateurBinaire::print(ostream& os) const
{
    /*gauche->print();
    printOperator(this->ident);
    droite->print();*/
    os << (*gauche) ;
    printOperator(os,this->ident);
    os << (*droite);
}

void OperateurBinaire::printOperator(ostream& os,Tokens id_symb) const
{
    string op = "OPP";
    switch(id_symb){
        case MINUS: op = " - "; break;
        case MULT:  op = " * "; break;
        case DIVIDE:op = " / "; break;
        case PLUS:  op = " + "; break;
        default: break;
    }
    os << op;
}

