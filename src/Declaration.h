#ifndef DECLARATION_H
#define DECLARATION_H

#include "Symbol.h"


class Declaration : public Symbol
{
    public:
        Declaration(TokenSymbol id,string n,double v):Symbol(id),nom(n),valeur(v){};
        virtual ~Declaration(){};
        virtual void print()=0;
        string get_nom(){return nom;}
        double get_valeur(){return valeur;}
    protected:
        string nom;
        double valeur;
    private:
};

#endif // DECLARATION_H
