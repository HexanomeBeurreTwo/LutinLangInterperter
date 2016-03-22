#ifndef PARTIEDECLARATIVE_H
#define PARTIEDECLARATIVE_H

#include "Symbol.h"
#include "Declaration.h"


class PartieDeclarative : public Symbol
{
    public:
        PartieDeclarative(): Symbol(PD){};
        virtual ~PartieDeclarative();
        bool add_declaration(Declaration *inst);
        void print(ostream& os) const ;
        Declrs& get_variables();
        void clear();

    protected:
        Declrs variables;
    private:
};

#endif // PARTIEDECLARATIVE_H
