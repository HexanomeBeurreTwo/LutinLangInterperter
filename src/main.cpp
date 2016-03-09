
#include <iostream>
using namespace std;

#include "AffectSymb.h"
#include "Expression.h"

#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "EcrireInstruction.h"

int main() {
    Expression *e;
    Variable* x = new Variable("x");
    Variable* y = new Variable("y");
    Valeur *val2 = new Valeur(2);


    Declrs vars;
    vars["x"] = new DeclarationConst("x",4.5);
    vars["y"] = new DeclarationVariable("y");

    vars["y"]->print();
    vars["x"]->print();

	AffectSymb affectation1(val2,y) ;
	affectation1.effectuer_affect(vars);
	affectation1.print();

    e = new OperateurPlus(new OperateurDiv(val2,x), new Parentese(new OperateurMoins(y,new Valeur(1.1))));

    AffectSymb affectation2(e,y) ;
    affectation2.effectuer_affect(vars);
	affectation2.print();

    EcrireInstruction* out = new EcrireInstruction(y);
    out->print();
    out->writes(vars);

    delete e;
    delete x;
    delete y;
    delete out;
    delete val2;

	return 0;

}


