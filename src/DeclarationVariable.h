#ifndef DECLARATIONVARIABLE_H
#define DECLARATIONVARIABLE_H

#include "Declaration.h"


class DeclarationVariable : public Declaration
{
    public:
        DeclarationVariable(string n):Declaration(VAR,n,0){};
        virtual ~DeclarationVariable(){};
        void print();
        void affect(double val);
    protected:

    private:
};

#endif // DECLARATIONVARIABLE_H
