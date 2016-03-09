#ifndef DECLARATIONCONST_H
#define DECLARATIONCONST_H

#include "Declaration.h"


class DeclarationConst : public Declaration
{
    public:
        DeclarationConst(string n,double v):Declaration(CONST,n,v){};
        virtual ~DeclarationConst(){};
        void print();
    protected:

    private:
};

#endif // DECLARATIONCONST_H
