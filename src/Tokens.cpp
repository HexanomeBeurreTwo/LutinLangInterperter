
#include "Tokens.h"

ostream& operator<< (ostream& os, const ValuableToken& t){
        switch(t.token){
                case VAR : os << "---VAR--" << endl; break;
                case CONST : os << "---CONST--" << endl; break;
                case AFFECT : os << "---AFFECT--" << endl; break;
                case EQUAL : os << "---EQUAL--" << endl; break;
                case SEP : os << "---SEP--" << endl; break;
                case WRITE : os << "---WRITE--" << endl; break;
                case READ : os << "---READ--" << endl; break;
                case END : os << "---END--" << endl; break;
                case ID : os << "---ID--" << endl; break;
                case VAL : os << "---VAL--" << endl; break;
                case MINUS : os << "---MINUS--" << endl; break;
                case OPENBY : os << "---OPENBY--" << endl; break;
                case CLOSEBY : os << "---CLOSEBY--" << endl; break;
                case MULT : os << "---MULT--" << endl; break;
                case DIVIDE : os << "---DIVIDE--" << endl; break;
                case PLUS : os << "---PLUS--" << endl; break;

				case P : os << "---P--" << endl; break;
				case PD : os << "---PD--" << endl; break;
				case LD : os << "---LD--" << endl; break;
				case LV : os << "---LV--" << endl; break;
				case LC : os << "---LC--" << endl; break;
				case D : os << "---D--" << endl; break;
				case PI : os << "---PI--" << endl; break;
				case LI : os << "---LI--" << endl; break;
				case E : os << "---E--" << endl; break;
				
				case INVALID : os << "---INVALID--" << endl; break;
				case END_OF_FILE : os << "---END_OF_FILE--" << endl; break;
		
				
                default : os << "Indefined !" << endl;
        }
        return os;
}


//Cette fonction est utilisé dans shift
bool is_terminal_token(const ValuableToken& t)
{
	bool res ;
	switch (t.token)
	{
		case VAR :
		case CONST:
		case AFFECT:
		case EQUAL :
		case SEP :
		case WRITE :
		case READ :
		case END :
		case ID:
		case VAL:
		case MINUS:
		case OPENBY:
		case CLOSEBY:
		case MULT:
		case DIVIDE:
		case PLUS: 
			res = true;
			break;
		default : res = false;
	}
	return res;
}