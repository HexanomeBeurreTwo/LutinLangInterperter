#include "Automaton.h"
#include "E0.h"
#include "State.h"
using namespace std;

Automaton::Automaton(void){

}

Automaton::~Automaton(void){

}

int Automaton::init(int nbParam, char * param[]){
	lexer = new Lexer();
	int error = lexer.init(param[nbParam -1]);

	return error;
}

void Automaton::read(){
	nextSymbol = lexer.getNext();
	E0 initState = new E0();
	stateStack.push(initState);
	while(nextSymbol != 'END_OF_FILE'){
		stateStack.top().transition(this, nextSymbol);
		nextSymbol = lexer.getNext();
	}
}

void Automaton::shift(Symbol s, State nextState){
	lexer.consume();
	symbolStack.push(s);
	stateStack.push(nextState);
}

void Automaton::reduce(int count, Symbol s){
	for(int i=0; i<count, i++){
		stateStack.pop();
	}
	stateStack.push(stateStack.top().transition(s));
}