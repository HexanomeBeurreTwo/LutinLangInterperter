#ifndef ECRIRE_H
#define ECRIRE_H

#include "Expression.h"
#include "Instruction.h"


class Ecrire : public Instruction
{
    public:
        Ecrire(Variable* var):Instruction(WRITE),variable(var){};
        virtual ~Ecrire();
        void print();
        bool writes(Declrs & variables);
    protected:
        Variable* variable;
    private:
};

#endif // ECRIRE_H
