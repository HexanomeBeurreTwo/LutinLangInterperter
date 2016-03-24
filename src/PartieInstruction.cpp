#include "Debug.h"
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


bool PartieInstruction::execute(Declrs & variables,bool silent)
{
    for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        if( ! (*it)->execute(variables,silent) )
        {
			
            return false;
        }
    }
    return true;
}



bool PartieInstruction::optimize(PartieInstruction *partie_instruction_opz, Declrs & variables)
{
	for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
		Instruction *inst = NULL ;
		
        if( ! (*it)->optimize(&inst,variables) )
        {
			DEBUG_STDOUT("PartieInstruction::optimize revoie false" << endl);
            return false;
        } else {
			DEBUG_STDOUT("\t"<< *(*it) << " ==> "<< (*inst) <<  endl);
			partie_instruction_opz -> add_instruction(inst);
			//cout << *partie_instruction_opz;
		}
    }
    return true;
	
}


