#ifndef ECRIREINSTRUCTION_H
#define ECRIREINSTRUCTION_H

#include "Expression.h"
#include "Instruction.h"


class EcrireInstruction : public Instruction
{
    public:
        EcrireInstruction(Variable* var):Instruction(WRITE),variable(var){};
        virtual ~EcrireInstruction();
        void print();
        bool writes(Declrs & variables);
    protected:
        Variable* variable;
    private:
};

#endif // ECRIREINSTRUCTION_H
