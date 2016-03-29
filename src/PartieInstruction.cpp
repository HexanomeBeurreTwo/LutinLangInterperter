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
    for (deque<Instruction*>::const_iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        os << *(*it) << endl;

    }

}

void PartieInstruction::add_instruction(Instruction *inst)//ajout a la fin
{
    instructions.push_back(inst);
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

bool PartieInstruction::analyse(Declrs & variables)
{
	bool res = true ;
    for (deque<Instruction*>::iterator it = instructions.begin(); it!=instructions.end(); ++it)
    {
        if( ! (*it)->analyse(variables) )
        {
            cerr << "une valeur dans l'expression " ; (*it)->get_expression(cerr) ; cerr << " n'est pas connue." << endl;

            res = false;
        }
    }
    return res;
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


