#ifndef PARTIEDECLARATIVE_H
#define PARTIEDECLARATIVE_H

#include "Symbol.h"
#include "Declaration.h"


class PartieDeclarative : public Symbol
{
    public:
        PartieDeclarative(): Symbol(PD){};
        virtual ~PartieDeclarative(){};
        bool add_declaration(Declaration *inst);
        void print() ;

    protected:
        Declrs variables;
    private:
};

#endif // PARTIEDECLARATIVE_H