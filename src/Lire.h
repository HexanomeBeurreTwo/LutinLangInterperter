#ifndef LIRE_H
#define LIRE_H

#include "Instruction.h"
#include "Expression.h"


class Lire : public Instruction
{
    public:
        Lire(Variable *var):Instruction(READ),variable(var){};
        virtual ~Lire();
        void print(ostream& os) const;
        bool execute(Declrs & variables);
        bool optimize(Instruction** inst,const Declrs & variables);
    protected:
        Variable* variable;
    private:
};

#endif // LIRE_H
