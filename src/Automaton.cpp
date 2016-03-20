#include "Automaton.h"
#include "States/E0.h"
#include "State.h"
using namespace std;


/*int Automaton::init(int nbParam, char * param[]){ // A faire dans le main
        lexer = new Lexer();
        int error = lexer.init(param[nbParam -1]);

        return error;
}*/

ostream& operator<< (ostream& os, const ValuableToken& t);

bool Automaton::read(){
	ValuableToken tmp;
	nextSymbol = lexer->getNext();
	cout << "in Automaton::read()" << endl;
	cout << nextSymbol << endl;
	if(nextSymbol.token == INVALID)
	{
		cerr << "Premier token INVALID " << endl;
		return false;
	}			
	E0* initState = new E0();
	stateStack.push(initState);
	while(nextSymbol.token != END_OF_FILE && 
		  nextSymbol.token != INVALID
	){
			cout << nextSymbol  << endl;
			if( !stateStack.top()->transition(this, nextSymbol) ) 
			{
				cerr << "Pas de transition "<< nextSymbol
					<< " possible sur l'etat " << stateStack.top()->getStateNumber() 
					<< endl;
				return false;
			}
			tmp = nextSymbol;
			nextSymbol = lexer->getNext();
			if(nextSymbol.token == INVALID)
			{
				cerr << "Token aprés " << tmp << "est invalide " <<endl;
				return false;
			} 
	}
	cout << nextSymbol  << endl;
    return true;
}

bool Automaton::shift(ValuableToken s, State* nextState){
        bool res = lexer->consumeNext();
        symbolStack.push(s);
        stateStack.push(nextState);
		if(!res)
		{
			cerr << "impossible de consommer le Token: " << s << endl; 
		}
		return res;
}

bool Automaton::reduce(int count, ValuableToken s, int coutSymbol ){
        for(int i=0; i<count; i++){
                stateStack.pop();
        }
        stateStack.top()->transition(this,s);
        bool res = programme->create_class_from_rules(&symbolStack,s,coutSymbol);
		if(!res)
		{
			cerr << "impossible de reduire la rélge Token: " << s << endl; 
		}
		return res;
}
