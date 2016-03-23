#ifndef ECRIRE_H
#define ECRIRE_H


#include "Instruction.h"
#include "Expression.h"
#include "Symbol.h"

class Ecrire : public Instruction
{
    public:
        Ecrire(Expression* exp):Instruction(WRITE),expression(exp){}
        virtual ~Ecrire();
        void print(ostream& os) const;
        bool execute(Declrs & variables);
        bool optimize(Instruction** inst,Declrs & variables) ;
    protected:
        Expression* expression;
    private:
};

#endif // ECRIRE_H
