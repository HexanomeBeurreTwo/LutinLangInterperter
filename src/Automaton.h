#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <stack>
#include "State.h"
#include "Symbol.h"
#include "Lexer.h"
class Automaton {
	public :

		Automaton();
		~Automaton();

		int init (int nbParam, char * param[]);
		void read();
		void shift(Symbol s, State nextState);
		void reduce(int count, Symbol s, State nextState);

	private :
	
		Symbol nextSymbol;
		stack <Symbol> symbolStack;
		stack <State> stateStack;
		Lexer lexer;
};

#endif