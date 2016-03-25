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
        void get_expression(ostream& os);
        bool execute(Declrs & variables);
        bool analyse(Declrs & variables);
        bool optimize(Instruction** inst,Declrs & variables);
    protected:
        Variable* variable;
    private:
};

#endif // LIRE_H
