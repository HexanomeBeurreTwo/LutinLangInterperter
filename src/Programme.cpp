#include "Debug.h"
#include "Programme.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "Expression.h"
#include "Affectation.h"
#include "Ecrire.h"
#include "Lire.h"
#include "Symbol.h"


#define TOKEN_VALUE_AS(x,type) *((type*)x.value)
#define TOKEN_VALUE_AS_POINTER(x,type) ((type*)x.value)


bool Programme::create_class_from_rules(std::stack<ValuableToken> *symbolStack,ValuableToken symbol,int countSymbol)
{
  ValuableToken tokens[countSymbol];
  ValuableToken str;
  Expression *e1,*e2;

  for(int i=countSymbol-1;i>-1;i--)
    {
      str = symbolStack->top();
      symbolStack->pop();
      tokens[i] = str;
    }
	
  DEBUG_STDOUT("~~~~~~~~~REDUCE~~~~~~~~"<< endl << symbol <<"  ==> " << endl);
  for(int i=0;i< countSymbol;i++)
    {
      str = tokens[i] ;
      DEBUG_STDOUT(str);
    }
  if(countSymbol ==0 ) DEBUG_STDOUT("---ε--" << endl);
  DEBUG_STDOUT("\n~~~~~~~~~~~~~~~~~~~~~~~" << endl);
	
  symbolStack->push(symbol);
	
  switch(symbol.token){ /** on fait rien dans certaines regles, car c'est déjà fait dans d'autres regles **/
  case P : // rule 1: P -> PD PI
    break;//on fait rien

  case PD : // rule 2: PD -> PD LD end
    // rule 3: PD -> ε
    break;//on fait rien

  case LD : // rule 4: LD -> var LV
            // rule 5: LD -> const LC
    break;//on fait rien

  case PI : // rule 6: PI -> PI LI end
            // rule 7: PI -> ε
    break;//on fait rien

  case LI :
    if(countSymbol == 3 && tokens[0].token == ID )
      // rule 8: LI -> id affect E
      {
	e1 = TOKEN_VALUE_AS_POINTER(tokens[2],Expression) ;
	partie_instruction.add_instruction(new Affectation(e1,new Variable(TOKEN_VALUE_AS(tokens[0],string))));
      }
    else if(countSymbol == 2 && tokens[0].token == WRITE )
      // rule 9: LI -> write E
      {
	e1 = TOKEN_VALUE_AS_POINTER(tokens[1],Expression) ; 
	partie_instruction.add_instruction(new Ecrire(e1));
      }
    else if(countSymbol == 2 && tokens[0].token == READ)
      // rule 10: LI -> read id
      {
	partie_instruction.add_instruction(new Lire(new Variable(TOKEN_VALUE_AS(tokens[1],string))));
      }
    break;

  case LV :
    if(countSymbol == 3 && tokens[0].token == LV)
      // rule 11: LV -> LV sep id
      {
	return partie_declaration.add_declaration(new DeclarationVariable(TOKEN_VALUE_AS(tokens[2],string)));
      }
    else if(countSymbol == 1 && tokens[0].token == ID)
      // rule 12: LV -> id
      {
	return partie_declaration.add_declaration(new DeclarationVariable(TOKEN_VALUE_AS(tokens[0],string)));
      }

    break;

  case LC : // rule 13: LC -> LC sep D
    // rule 14: LC -> D
    break;//on fait rien

  case D : // rule 15: D -> id equal val
    return partie_declaration.add_declaration(new DeclarationConst(TOKEN_VALUE_AS(tokens[0],string),TOKEN_VALUE_AS(tokens[2],double)));
    break;

  case E :
    if(countSymbol == 3 && tokens[0].token == OPENBY)
      // rule 20: E -> ( E )
      {
	e1 = TOKEN_VALUE_AS_POINTER(tokens[1],Expression) ; 
	symbolStack -> top() . value = new Parentese(e1);
                
      }
    else if(countSymbol == 3 )
      {
	e1 = TOKEN_VALUE_AS_POINTER(tokens[0],Expression) ;
	e2 = TOKEN_VALUE_AS_POINTER(tokens[2],Expression) ;
				
	if(tokens[1].token == PLUS)
	  // rule 16: E -> E + E
	  {
	    symbolStack -> top() . value = new OperateurPlus(e1,e2);
	  }
	else if(tokens[1].token == MINUS)
	  // rule 17: E -> E - E
	  {
	    symbolStack -> top() . value = new OperateurMoins(e1,e2);
	  }
	else if(tokens[1].token == DIVIDE)
	  // rule 18: E -> E / E
	  {
	    symbolStack -> top() . value = new OperateurDiv(e1,e2);
	  }
	else if(tokens[1].token == MULT)
	  // rule 19: E -> E * E
	  {
	    symbolStack -> top() . value = new OperateurMul(e1,e2);
	  }
      }
    else if(countSymbol == 1)
      {
	if(tokens[0].token == ID)
	  // rule 21: E -> id
	  {
	    symbolStack -> top() . value = new Variable(TOKEN_VALUE_AS(tokens[0],string));
	  }
	else if(tokens[0].token == VAL)
	  // rule 22: E -> val
	  {
	    symbolStack -> top() . value = new Valeur(TOKEN_VALUE_AS(tokens[0],double));
	  }
      }

    break;

  default:
    std::cerr << "Indefined rule !" << endl;
    return false;
    break;
  }

  return true;
}

void Programme::print(ostream& os)const
{
  os << partie_declaration << partie_instruction ;
}




Programme::~Programme()
{

}

bool Programme::optimize(Programme* programme)
{
  bool res;
	 
  programme->partie_declaration.clone_vars(partie_declaration);
	 
  res =  partie_instruction.optimize(&programme->partie_instruction,programme->partie_declaration.get_variables());
  if(res) 
    {
      //programme->partie_declaration.optimize(); // on a dit qu'on enlève pas les const
    }
  return res;
}
 
 
bool Programme::analyse()
{
  bool res = do_analyse();
  //if(!res)// D'abord execution en mode silence
  //{
  check_undeclared();
  check_uninitialized_var();
		
  //}
  check_unused_vars();
  return res;
}

void Programme::check_uninitialized_var()
{
  partie_declaration.check_uninitialized_var();
}

void Programme::check_unused_vars()
{
  partie_declaration.check_unused_vars();
}

void Programme::check_undeclared() 
{
  partie_declaration.check_undeclared();
}

bool Programme::do_analyse() 
{
  return partie_instruction.analyse(partie_declaration.get_variables());
}


bool Programme::execute()
{
  //DEBUG_STDOUT("Programme::execute()" << endl);
  return partie_instruction.execute(partie_declaration.get_variables());
}

