
#include <iostream>
using namespace std;

#include "Affectation.h"
#include "Expression.h"

#include "PartieDeclarative.h"
#include "PartieInstruction.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "EcrireInstruction.h"
#include "Lire.h"
#include "Ecrire.h"


void test1()
{
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
	affectation1.execute(vars);
	affectation1.print();

    e = new OperateurPlus(new OperateurDiv(val2,x), new Parentese(new OperateurMoins(y,new Valeur(1.1))));

    Affectation affectation2(e,y) ;
    affectation2.execute(vars);
	affectation2.print();


    Lire* in = new Lire(new Variable("z"));
    in -> print();
    in->execute(vars);

    /*Ecrire* out = new Ecrire(new Variable("y"));
    out->print();
    out->execute(vars);*/

    //out = new Ecrire(new Variable("z"));
    //out->print();
    //out->execute(vars);

    delete e;
    //delete in;
    delete x;
    delete y;
    //delete out;
    delete val2;


}


int main() {
    PartieDeclarative* PD = new PartieDeclarative();
    PartieInstruction* PI = new PartieInstruction();
    bool succes ;

    succes = PD->add_declaration(new DeclarationConst("x",4.5)) ;
    succes = succes && PD->add_declaration(new DeclarationVariable("y"));
    succes = succes && PD->add_declaration(new DeclarationVariable("z"));

    if(!succes)
    {
        cout << "Erreur partie declarative!"<<endl;
        return 1;
    }

    PD->print();

    PI->add_instruction(new Affectation(new Valeur(2),new Variable("y")));
    Expression* e = new OperateurPlus(new OperateurDiv(new Valeur(4),new Variable("x")), new Parentese(new OperateurMoins(new Variable("y"),new Valeur(1.1))));
    PI->add_instruction(new Affectation(e,new Variable("y")));
    PI->add_instruction(new Lire(new Variable("z")));
    PI->add_instruction(new Ecrire(new Variable("x")));
    PI->add_instruction(new Ecrire(new Variable("y")));
    PI->add_instruction(new Ecrire(new Variable("z")));

    PI->print();

    succes = PI->execute(PD->get_variables());

    if(!succes)
    {
        cout << "Erreur d'execution" << endl;
        return 1;
    }

    delete PI;
    delete PD;
    return 0;

}


