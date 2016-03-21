#ifndef _EXPR_H
#define _EXPR_H

#include <string>

#include "Instruction.h"



class Expression  : public Symbol{
   public:
      Expression(Tokens id_symb):Symbol(id_symb){};
      //Expression():Instruction(E){};
      virtual ~Expression(){};
      virtual void print(ostream& os) const  = 0;
      virtual bool Evaluation(double* res,const Declrs & variables) = 0;
	  
};

class Valeur: public Expression {
   // une expression composée uniquement d'une valeur double
   public:
      Valeur(int val):Expression(VAL),valeur(val){};
      Valeur(double val):Expression(VAL),valeur(val){};
      ~Valeur(){};
      bool Evaluation(double* res,const Declrs & variables);
      void print(ostream& os) const;
   protected:
      double valeur;

};

class Variable: public Expression {
   // une expression composée uniquement d'une variable
   public:
      Variable(string n):Expression(VAR),nom(n){};
      ~Variable(){};
      bool Evaluation(double* res,const Declrs & variables);
      void print(ostream& os) const;
      string get_nom(){return nom;}
   protected:
      string nom;
};

class Parentese: public Expression {
   public:
      Parentese(Expression * expr):Expression(OPENBY),expression(expr){};
      ~Parentese(){delete expression;};
      void print(ostream& os) const;
      bool Evaluation(double* res,const Declrs & variables);
   protected:
      Expression *expression;
};

class OperateurBinaire: public Expression { // MINUS MULT DIVIDE PLUS
   // un opérateur binaire générique, pour l'implémenter, il faut
   // implémenter la méthode operation()
   public:
      OperateurBinaire(Tokens id_symb,Expression * g, Expression * d):Expression(id_symb),gauche (g),droite (d){};
      ~OperateurBinaire();
      bool Evaluation(double *res,const Declrs & variables);
      void print(ostream& os) const;
   protected:
      virtual double operation(double g, double d) = 0;
      void printOperator(ostream& os, Tokens id_symb) const;
      Expression * gauche;
      Expression * droite;
};

class OperateurPlus: public OperateurBinaire {
   public:
      OperateurPlus(Expression * g, Expression * d):OperateurBinaire(PLUS,g,d){};
      ~OperateurPlus(){};
   protected:
      double operation(double g, double d);
};

class OperateurMoins: public OperateurBinaire {
   public:
      OperateurMoins(Expression * g, Expression * d):OperateurBinaire(MINUS,g,d){};
      ~OperateurMoins(){};
   protected:
      double operation(double g, double d);
};

class OperateurDiv: public OperateurBinaire {
   public:
      OperateurDiv(Expression * g, Expression * d):OperateurBinaire(DIVIDE,g,d){};
      ~OperateurDiv(){};
   protected:
      double operation(double g, double d);
};

class OperateurMul: public OperateurBinaire {
   public:
      OperateurMul(Expression * g, Expression * d):OperateurBinaire(MULT,g,d){};
      ~OperateurMul(){};
   protected:
      double operation(double g, double d);
};



#endif
