#ifndef DECLARATIONCONST_H
#define DECLARATIONCONST_H

#include "Declaration.h"


class DeclarationConst : public Declaration
{
    public:
        DeclarationConst(string n,double v):Declaration(CONST,n,v,true){};
        virtual ~DeclarationConst(){};
        void print(ostream& os) const;
    protected:

    private:
};

#endif // DECLARATIONCONST_H
