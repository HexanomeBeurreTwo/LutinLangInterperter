
#include <iostream>
using namespace std;

#include "Affectation.h"
#include "Expression.h"

#include "PartieDeclarative.h"
#include "PartieInstruction.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "Lire.h"
#include "Ecrire.h"


int main_ut()
{
    Expression *e;
    Variable* x = new Variable("x");
    Variable* y = new Variable("y");
    Valeur *val2 = new Valeur(2);


    Declrs vars;
    vars["x"] = new DeclarationConst("x",4.5);
    vars["y"] = new DeclarationVariable("y");

    cout << *vars["y"];
    cout << *vars["x"];

	Affectation affectation1(val2,y) ;
	//affectation1.execute(vars);
	//affectation1.print();
	cout << affectation1;

    e = new OperateurPlus(new OperateurDiv(val2,x), new Parentese(new OperateurMoins(y,new Valeur(1.1))));

    Affectation affectation2(e,y) ;
    //affectation2.execute(vars);
	//affectation2.print();
	cout << affectation2;


    Lire* in = new Lire(new Variable("z"));
    //in -> print();
    cout << in ;
    //in->execute(vars);

    /*Ecrire* out = new Ecrire(new Variable("y"));
    out->print();
    out->execute(vars);*/

    //out = new Ecrire(new Variable("z"));
    //out->print();
    //out->execute(vars);

    //delete e;
    //delete in;
    //delete x;
    //delete y;
    //delete out;
    //delete val2;

	return 1;
}


int main_y() {
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

    cout << *PD;

    PI->add_instruction(new Affectation(new Valeur(2),new Variable("y")));
    Expression* e = new OperateurPlus(new OperateurDiv(new Valeur(4),new Variable("x")), new Parentese(new OperateurMoins(new Variable("y"),new Valeur(1.1))));
    PI->add_instruction(new Affectation(e,new Variable("y")));
    PI->add_instruction(new Lire(new Variable("z")));
    PI->add_instruction(new Ecrire(new Variable("x")));
    PI->add_instruction(new Ecrire(new Variable("y")));
    PI->add_instruction(new Ecrire(new Variable("z")));

    //PI->print();
    cout << *PI;

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


int main_ii() {
    PartieDeclarative* PD = new PartieDeclarative();
    PartieInstruction* PI = new PartieInstruction();
    bool succes ;

    succes = PD->add_declaration(new DeclarationConst("pi",3.14)) ;
    succes = succes && PD->add_declaration(new DeclarationVariable("rayon"));
    succes = succes && PD->add_declaration(new DeclarationVariable("hauteur"));
    succes = succes && PD->add_declaration(new DeclarationVariable("VolumeCylindre"));
	succes = succes && PD->add_declaration(new DeclarationVariable("a"));

    if(!succes)
    {
        cout << "Erreur partie declarative!"<<endl;
        return 1;
    }

  
    cout << *PD;


    PI->add_instruction(new Lire(new Variable("rayon")));
    PI->add_instruction(new Lire(new Variable("hauteur")));
    Expression* e = new OperateurMul(new Variable("hauteur"),new OperateurMul(new Variable("pi"),new OperateurMul(new Variable("rayon"),new Variable("rayon"))));
    PI->add_instruction(new Affectation(e,new Variable("VolumeCylindre")));
    //PI->add_instruction(new Ecrire(new Variable("VolumeCylindre")));
	//PI->add_instruction(new Ecrire(new OperateurPlus(new OperateurDiv(new Valeur(4),new Variable("VolumeCylindre")), new Parentese(new OperateurMoins(new Variable("rayon"),new Valeur(1.1))))));
  
	//"a := (c+d)*3-5;";
	Expression* e1 = new OperateurMoins(new OperateurMul(new Parentese(new OperateurPlus(new Variable("pi"),new Variable("pi"))),new Valeur(3)),new Valeur(5));
	//PI->add_instruction(new Ecrire(e1));
	PI->add_instruction(new Affectation(e1,new Variable("a")));
	PI->add_instruction(new Ecrire(new Variable("a")));
  
    cout << *PI;

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

