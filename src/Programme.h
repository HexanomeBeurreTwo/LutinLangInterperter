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
        Programme(){};
        virtual ~Programme();
        bool create_class_from_rules(stack<ValuableToken> *symbolStack,ValuableToken symbol,int countSymbol);
        void print(ostream& os) const ;
        bool execute();
        void optimize(){};
    protected:

    private:
        deque<Expression*> expressions; // une file d'expression ordonnée selon date creation
        PartieInstruction partie_instruction;
        PartieDeclarative partie_declaration;
		

    friend ostream& operator<< (ostream& os, const Programme& programme)
    {
        programme.print(os);
        return os ;
    }
};

#endif // PROGRAMME_H
