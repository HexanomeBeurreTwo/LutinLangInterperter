
#include <iostream>
using namespace std;

#include "AffectSymb.h"
#include "Expression.h"

int main() {
    Expression *e;
    map<string,double> var;
    var["x"] = 5.;
    var["y"] = -4.;

    /*Valeur* e = new Valeur(4.5);
    Variable v("A");
	AffectSymb symbole(e,v) ;
	symbole.print();*/

	e = new OperateurPlus(new OperateurDiv(new Valeur(2),new Variable("x")), new Variable("y"));
    cout <<"l'evaluation de ";
    e->print();
    cout << "pour x=" << var["x"]
         << " et y="  << var["y"]
         <<" donne : "<< e->Evaluation(var) << "\n";
    delete e;
	return 0;

}


