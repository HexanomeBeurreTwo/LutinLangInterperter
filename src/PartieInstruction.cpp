#include "PartieInstruction.h"
#include "Instruction.h"
#include "Symbol.h"


PartieInstruction::~PartieInstruction()
{
    for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        delete (*it);
    }
}

void PartieInstruction::print(ostream& os) const
{
    // parcours de deque + \n + appel a print()
    for (deque<Instruction*>::const_iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        /*(*it)->print();
        cout << endl; */
        os << *(*it) << endl;

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


bool PartieInstruction::optimize(PartieInstruction *partie_instruction_opz,const Declrs & variables)
{
	for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
		Instruction *inst = NULL ;
		
        if( ! (*it)->optimize(&inst,variables) )
        {
			cerr << "PartieInstruction::optimize revoie false" << endl;
            return false;
        } else {
			cerr << "optimisation réussie pour "<< (*inst) << endl;
			//partie_instruction_opz -> add_instruction(inst);
			
			 
		}
    }
    return true;
	
}


PartieInstruction::PartieInstruction(const PartieInstruction& other): Symbol(PI)
{
	for (deque<Instruction*>::const_iterator it = other.instructions.begin(); it!=other.instructions.end(); ++it)
    {
		instructions.push_front(*it);
    }
	
}
