
#include <iostream>
using namespace std;

#include "Affectation.h"
#include "Expression.h"

#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "EcrireInstruction.h"
#include "Lire.h"

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

	Affectation affectation1(val2,y) ;
	affectation1.effectuer_affect(vars);
	affectation1.print();

    e = new OperateurPlus(new OperateurDiv(val2,x), new Parentese(new OperateurMoins(y,new Valeur(1.1))));

    Affectation affectation2(e,y) ;
    affectation2.effectuer_affect(vars);
	affectation2.print();

    Ecrire* out = new Ecrire(y);
    out->print();
    out->writes(vars);

    Lire* in = new Lire(new Variable("z"));
    in -> print();
    in->reads(vars);

    delete e;
    delete in;
    delete x;
    delete y;
    delete out;
    delete val2;

	return 0;

}


