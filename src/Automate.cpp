#include lexer.h

//StatesStack
//Lexer
//SymboleStatck

init([options,...,file])	{
	//lexer = Lexer();
	lexer.init(file);
	States.push(E0);

	Automate.lire();
	return error;
}

void lire()	{
	Symbole next = getNext();

	while(next != 'END_OF_FILE')	{
		CurrentState().transition(next);
		// Some code...

		next = getNext();
	}
}


void decalage(Symbole s, State nextState)	{
	// consommer(s);
	// states.push(nextState);
	// symbols.push(s);
}

void reduction(int count, Symbol s, State nextState)	{
	//depiler{count} fois state
	// symbols.push(s);
	// State.push(nextState);
}