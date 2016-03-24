#ifndef DECLARATION_H
#define DECLARATION_H

#include "Symbol.h"


class Declaration : public Symbol
{
    public:
        Declaration(Tokens id,string n,double v,bool initzd):
		Symbol(id),nom(n),valeur(v),used(false),initialized(initzd){};
        virtual ~Declaration(){};
        virtual void print(ostream& os) const=0;
        string get_nom(){return nom;}
        double get_valeur(){return valeur;}
		bool is_used(){return used;}
		bool is_initialized(){return initialized;}
		void set_used(){used = true;}
    protected:
        string nom;
        double valeur;
        bool used;
        bool initialized;
    private:
};

#endif // DECLARATION_H
