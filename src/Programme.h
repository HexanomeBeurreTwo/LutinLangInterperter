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
        virtual ~Programme(){};
        bool create_class_from_rules(stack<ValuableToken> *symbolStack,ValuableToken symbol,int countSymbol);
        void print();
        bool execute();
        void optimize(){};
    protected:

    private:
        deque<Expression*> expressions; // une file d'expression ordonnée selon date creation
        PartieInstruction partie_instruction;
        PartieDeclarative partie_declaration;
};

#endif // PROGRAMME_H
