#ifndef PROGRAMME_H
#define PROGRAMME_H

#include <iostream>
#include <stack>

#include "Expression.h"
#include "PartieDeclarative.h"
#include "PartieInstruction.h"
#include "Tokens.h"


class Programme
{
    public:
        Programme():id_expression(0){};
        virtual ~Programme();
        bool create_class_from_rules(stack<ValuableToken> *symbolStack,ValuableToken symbol,int countSymbol);
        void print(ostream& os) const ;
        bool execute();
		bool do_analyse();
        bool optimize(Programme* programe);
		bool analyse();
    protected:

    private:
		void check_uninitialized_var(); // OK ! 
		void check_unused_vars(); // OK !
		void check_undeclared(); // OK !
		Expression* get_expression(int index);
		
        //deque<Expression*> expressions; // une file d'expression ordonnée selon date creation
		map<int,Expression*> expressions;
        PartieInstruction partie_instruction;
        PartieDeclarative partie_declaration;
		int id_expression;
		

    friend ostream& operator<< (ostream& os, const Programme& programme)
    {
        programme.print(os);
        return os ;
    }
};

#endif // PROGRAMME_H
