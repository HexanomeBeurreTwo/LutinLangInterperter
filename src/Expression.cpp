#include "Expression.h"
#include <iostream>
#include "Declaration.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "Symbol.h"

using namespace std;


double Valeur::Evaluation(const Declrs & variables) {
   return this->valeur;
}


double Variable::Evaluation(const Declrs & variables) {
   Declrs::const_iterator var = variables.find(nom);
   if (var!=variables.end()) {
      return (var->second)->get_valeur();
   } else {
      return .0;
   }
}

OperateurBinaire::~OperateurBinaire() {
   delete gauche;
   delete droite;
}

double OperateurBinaire::Evaluation(const Declrs & variables) {
   double valg,vald;
   valg = gauche->Evaluation(variables);
   vald = droite->Evaluation(variables);
   return operation(valg,vald);
}

double Parentese::Evaluation(const Declrs & variables) {
   return expression->Evaluation(variables);
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

