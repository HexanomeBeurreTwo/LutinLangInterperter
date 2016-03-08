

#include <iostream>
using namespace std;

#include "AffectSymb.h"
#include "Expression.h"

int main() {
    Valeur* e = new Valeur(4.5);
    Variable v("A");
	AffectSymb symbole(e,v) ;
	symbole.print();

	return 0;

}


