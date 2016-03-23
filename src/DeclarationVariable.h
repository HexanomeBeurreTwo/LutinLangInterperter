#ifndef DECLARATIONVARIABLE_H
#define DECLARATIONVARIABLE_H

#include "Declaration.h"


class DeclarationVariable : public Declaration
{
    public:
        DeclarationVariable(string n):Declaration(VAR,n,0,false){};
        virtual ~DeclarationVariable(){};
        void print(ostream& os) const;
        void affect(double val);
        
    protected:

    private:
};

#endif // DECLARATIONVARIABLE_H
