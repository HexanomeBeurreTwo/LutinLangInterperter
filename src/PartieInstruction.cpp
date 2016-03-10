#include "PartieInstruction.h"


PartieInstruction::~PartieInstruction()
{
    for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        delete (*it);
    }
}

void PartieInstruction::print()
{
    // parcours de deque + \n + appel a print()
    for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        (*it)->print();
        cout << endl;
    }

}

void PartieInstruction::add_instruction(Instruction *inst)//ajout a la fin
{
    instructions.push_back(inst);
    //return true;
}


bool PartieInstruction::execute(Declrs & variables)
{
    for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        if( ! (*it)->execute(variables) )
        {
            return false;
        }
    }
    return true;
}

