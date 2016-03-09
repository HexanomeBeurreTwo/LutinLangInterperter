#ifndef LIREINSTRUCTION_H
#define LIREINSTRUCTION_H

#include "Instruction.h"
#include "Expression.h"


class LireInstruction : public Instruction
{
    public:
        LireInstruction(Variable *var):Instruction(READ),variable(var){};
        virtual ~LireInstruction();
        void print();
        bool reads(Declrs & variables);
    protected:
        Variable* variable;
    private:
};

#endif // LIREINSTRUCTION_H
