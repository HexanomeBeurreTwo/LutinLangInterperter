#ifndef DECLARATION_H
#define DECLARATION_H

#include "Symbol.h"


class Declaration : public Symbol
{
    public:
        Declaration(Tokens id,string n,double v):Symbol(id),nom(n),valeur(v){};
        virtual ~Declaration(){};
        virtual void print(ostream& os) const=0;
        string get_nom(){return nom;}
        double get_valeur(){return valeur;}
    protected:
        string nom;
        double valeur;
        bool deja_utilisee;
    private:
};

#endif // DECLARATION_H
