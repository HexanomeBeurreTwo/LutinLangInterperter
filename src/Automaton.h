#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <stack>
#include "State.h"
#include "Tokens.h"
#include "Lexer.h"
#include "Programme.h"


class Automaton {
	public :

		Automaton(Lexer *lex,Programme*prog):lexer(lex),programme(prog){};
		~Automaton(){};

		bool read();
		bool shift(ValuableToken& s, State* nextState);
		bool reduce(int count, ValuableToken& s, int coutSymbol);
		Lexer* getLexer(){return lexer;}

	private :

		ValuableToken nextSymbol;
		stack <ValuableToken> symbolStack;
		stack <State*> stateStack;
		Lexer *lexer;
		Programme* programme;
};

#endif
