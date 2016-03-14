#include "Automaton.h"
#include "States/E0.h"
#include "State.h"
using namespace std;


/*int Automaton::init(int nbParam, char * param[]){ // A faire dans le main
	lexer = new Lexer();
	int error = lexer.init(param[nbParam -1]);

	return error;
}*/

bool Automaton::read(){
	nextSymbol = lexer->getNext();
	if(nextSymbol.token == INVALID) return false;
	E0* initState = new E0();
	stateStack.push(initState);
	while(nextSymbol.token != END_OF_FILE){
		if( !stateStack.top()->transition(this, nextSymbol) ) return false;
		nextSymbol = lexer->getNext();
		if(nextSymbol.token == INVALID) return false;
	}
    return true;
}

void Automaton::shift(ValuableToken s, State* nextState){
	lexer->consumeNext();
	symbolStack.push(s);
	stateStack.push(nextState);
}

bool Automaton::reduce(int count, ValuableToken s, int coutSymbol, State* nextState ){
	for(int i=0; i<count; i++){
		stateStack.pop();
	}
	stateStack.push(nextState);
	return programme->create_class_from_rules(&symbolStack,s,coutSymbol);
}



