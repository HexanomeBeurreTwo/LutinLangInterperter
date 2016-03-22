#ifndef PARTIEINSTRUCTION_H
#define PARTIEINSTRUCTION_H

#include <iostream>
#include <deque>

#include "Symbol.h"
#include "Instruction.h"


using namespace std;


class PartieInstruction : public Symbol
{
    public:
        PartieInstruction(): Symbol(PI){};
        PartieInstruction(const PartieInstruction& other);
        virtual ~PartieInstruction();
        void add_instruction(Instruction *inst);
        void print(ostream& os) const;
        bool execute(Declrs & variables);
        bool optimize(PartieInstruction *partie_instruction_opz,const Declrs & variables);

    protected:
        deque<Instruction*> instructions; // une file d'instruction


    private:
};

#endif // PARTIEINSTRUCTION_H
