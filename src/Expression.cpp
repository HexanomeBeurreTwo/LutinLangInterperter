#include "Expression.h"
#include <cmath>
#include<iostream>
#include "Declaration.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"

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
   //delete gauche;
   //delete droite;
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

void Variable::print(){
    cout <<" "<<nom<<" ";
}

void Valeur::print(){
    cout <<" "<<valeur<<" ";
}

void Parentese::print(){
    cout << "(" ;
    expression->print();
    cout << ")";
}
void OperateurBinaire::print(){
    gauche->print();
    printOperator(this->ident);
    droite->print();
}

void OperateurBinaire::printOperator(TokenSymbol id_symb){
    string op = "OPP";
    switch(id_symb){
        case MINUS: op = "-"; break;
        case MULT:  op = "*"; break;
        case DIVIDE:op = "/"; break;
        case PLUS:  op = "+"; break;
        default: break;
    }
    cout << op;
}

