#ifndef ECRIRE_H
#define ECRIRE_H


#include "Instruction.h"
#include "Expression.h"
#include "Symbol.h"

class Ecrire : public Instruction
{
    public:
        Ecrire(Variable* var):Instruction(WRITE),variable(var){};
        virtual ~Ecrire();
        void print(ostream& os) const;
        bool execute(Declrs & variables);
    protected:
        Variable* variable;
    private:
};

#endif // ECRIRE_H
