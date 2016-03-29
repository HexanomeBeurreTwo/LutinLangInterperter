
#include "Tokens.h"

ostream& operator<< (ostream& os, const ValuableToken& t){
  switch(t.token){
  case VAR : os << "---VAR--"; break;
  case CONST : os << "---CONST--"; break;
  case AFFECT : os << "---AFFECT--"; break;
  case EQUAL : os << "---EQUAL--"; break;
  case SEP : os << "---SEP--"; break;
  case WRITE : os << "---WRITE--"; break;
  case READ : os << "---READ--"; break;
  case END : os << "---END--"; break;
  case ID : os << "---ID--"; break;
  case VAL : os << "---VAL--"; break;
  case MINUS : os << "---MINUS--"; break;
  case OPENBY : os << "---OPENBY--"; break;
  case CLOSEBY : os << "---CLOSEBY--"; break;
  case MULT : os << "---MULT--"; break;
  case DIVIDE : os << "---DIVIDE--"; break;
  case PLUS : os << "---PLUS--"; break;

  case P : os << "---P--"; break;
  case PD : os << "---PD--"; break;
  case LD : os << "---LD--"; break;
  case LV : os << "---LV--"; break;
  case LC : os << "---LC--"; break;
  case D : os << "---D--"; break;
  case PI : os << "---PI--"; break;
  case LI : os << "---LI--"; break;
  case E : os << "---E--"; break;
				
  case INVALID : os << "---INVALID--"; break;
  case END_OF_FILE : os << "---END_OF_FILE--"; break;
		
				
  default : os << "Indefined !";
  }
  return os;
}

ostream& operator<< (ostream& os, const Cursor& c){
  os << "(" << c.line << ":" << c.column << ")";
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
