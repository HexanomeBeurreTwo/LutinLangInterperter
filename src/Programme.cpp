

#include "Programme.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "Expression.h"
#include "Affectation.h"
#include "Ecrire.h"
#include "Lire.h"


#define VALUE_AS(x,type) *((type*)x.value)

void Programme::create_class_from_rules(std::stack<ValuableToken> *symbolStack,ValuableToken symbol,int countSymbol)
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
                e1 = expressions.front();expressions.pop_front();
                partie_instruction.add_instruction(new Affectation(e1,new Variable(VALUE_AS(tokens[0],string))));
            }
            else if(countSymbol == 2 && tokens[0].token == WRITE )
            // rule 9: LI -> write id
            {
                partie_instruction.add_instruction(new Ecrire(new Variable(VALUE_AS(tokens[1],string))));
            }
            else if(countSymbol == 2 && tokens[0].token == READ)
            // rule 10: LI -> read id
            {
                partie_instruction.add_instruction(new Lire(new Variable(VALUE_AS(tokens[1],string))));
            }
        break;

    case LV :
            if(countSymbol == 3 && tokens[0].token == LV)
            // rule 11: LV -> LV sep id
            {
                partie_declaration.add_declaration(new DeclarationVariable(VALUE_AS(tokens[2],string)));
            }
            else if(countSymbol == 1 && tokens[0].token == ID)
              // rule 12: LV -> id
            {
                partie_declaration.add_declaration(new DeclarationVariable(VALUE_AS(tokens[0],string)));
            }

        break;

    case LC : // rule 13: LC -> LC sep D
              // rule 14: LC -> D
        break;//on fait rien

    case D : // rule 15: D -> id equal val
        partie_declaration.add_declaration(new DeclarationConst(VALUE_AS(tokens[0],string),VALUE_AS(tokens[2],double)));
        break;

    case E :
            if(countSymbol == 3 )
            {
                e1 = expressions.front();expressions.pop_front();
                e2 = expressions.front();expressions.pop_front();
                if(tokens[1].token == PLUS)
                // rule 16: E -> E + E
                {
                    expressions.push_back(new OperateurPlus(e1,e2));
                }
                else if(tokens[1].token == MINUS)
                // rule 17: E -> E - E
                {
                    expressions.push_back(new OperateurMoins(e1,e2));
                }
                else if(tokens[1].token == DIVIDE)
                // rule 18: E -> E / E
                {
                    expressions.push_back(new OperateurDiv(e1,e2));
                }
                else if(tokens[1].token == MULT)
                // rule 19: E -> E * E
                {
                    expressions.push_back(new OperateurMul(e1,e2));
                }
            }
            else if(countSymbol == 3 && tokens[0].token == OPENBY)
            // rule 20: E -> ( E )
            {
                e1 = expressions.front();expressions.pop_front();
                expressions.push_back(new Parentese(e1));
            }
            else if(countSymbol == 1)
            {
                if(tokens[0].token == ID)
                // rule 21: E -> id
                {
                    expressions.push_back(new Variable(VALUE_AS(tokens[0],string)));
                }
                else if(tokens[0].token == VAL)
                // rule 22: E -> val
                {
                    expressions.push_back(new Valeur(VALUE_AS(tokens[0],double)));
                }
            }

        break;

        default: // pour le debug
            std::cerr << "Indifined rule !" << endl;
            break;
    }
}

void Programme::print()
{
    partie_declaration.print();
    partie_instruction.print();
}

bool Programme::execute()
{
    return partie_instruction.execute(partie_declaration.get_variables());
}