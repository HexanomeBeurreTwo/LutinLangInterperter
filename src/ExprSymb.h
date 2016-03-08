#ifndef EXPRSYMB_H
#define EXPRSYMB_H

#include "Symbol.h"

class ExprSymb : public Symbol
{
    public:
        ExprSymb(TokenSymbol id_symb):Symbol(E){};
        ExprSymb():Symbol(E){};
        virtual ~ExprSymb();
        virtual void print();

    protected:

    private:
};

#endif // EXPRSYMB_H
