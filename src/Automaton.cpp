#include "Debug.h"
#include "Automaton.h"
#include "States/E0.h"
#include "State.h"
using namespace std;

#define Accepte_STATE 18

/*int Automaton::init(int nbParam, char * param[]){ // A faire dans le main
        lexer = new Lexer();
        int error = lexer.init(param[nbParam -1]);

        return error;
}*/

ostream& operator<< (ostream& os, const ValuableToken& t);

bool Automaton::read(){
	bool end = false;
	ValuableToken tmp;
	State *tmpSt;
	nextSymbol = lexer->getNext();
	DEBUG_STDOUT ( nextSymbol << endl ) ;

	if(nextSymbol.token == INVALID)
	{
		DEBUG_STDERR( "Premier token INVALID " << endl);
		return false;
	}			
	E0* initState = new E0();
	stateStack.push(initState);
	while(!end && 
		  nextSymbol.token != INVALID
	){

			DEBUG_STDOUT ( nextSymbol  << endl ) ;
			tmpSt = stateStack.top();
			if( !tmpSt->transition(this, nextSymbol) ) 
			{
				DEBUG_STDERR( "Pas de transition "<< nextSymbol
					<< " possible dans l'etat " << tmpSt->getStateNumber() 
					<< endl);


			// TODO: Detect Const Var error and raise it
			// TODO: Detect Var Const error and raise it
			return false;
		}
		if(nextSymbol.token == END_OF_FILE) {
			end = true;
			bool res = stateStack.top()->getStateNumber() == Accepte_STATE;


				if(res) DEBUG_STDOUT( "Automate ok!" << endl );
				return res;
			}
			tmp = nextSymbol;
			nextSymbol = lexer->getNext();
			if(nextSymbol.token == INVALID)
			{
				DEBUG_STDERR( "Token apres " << tmp << "est invalide " <<endl);
				return false;
			} 

	}
	DEBUG_STDOUT ( nextSymbol  << endl);
    return false;
}



bool Automaton::shift(ValuableToken& s, State* nextState){
        bool res = true;
		if(is_terminal_token(s)) 
		{
			res = lexer->consumeNext();
			DEBUG_STDOUT ( "Consommation de " << s );
				// << "le suivant est " << lexer->getNext();
			symbolStack.push(s);
		}
        //symbolStack.push(s);
        stateStack.push(nextState);
		DEBUG_STDOUT ( "Shift vers l'etat [ " << nextState->getStateNumber()  
			 << " ] Avec " << s << endl );

		if(!res)
		{
			DEBUG_STDERR ( "impossible de consommer le Token: " << s << endl); 
		}
		return res;
}

bool Automaton::reduce(int count, ValuableToken& s, int coutSymbol ){
        for(int i=0; i<count; i++){
                stateStack.pop();
        }
		DEBUG_STDOUT ("Reduce vers l'etat [ " << stateStack.top()->getStateNumber()  <<" ]" << endl );
        stateStack.top()->transition(this,s);
        bool res = programme->create_class_from_rules(&symbolStack,s,coutSymbol);
		if(!res)
		{
			DEBUG_STDERR( "impossible de reduire la rélge " << s << " -> .."<<endl ); 
		}
		return res;
}
