#ifndef _EXPR_H
#define _EXPR_H

#include <string>
#include <map>

#include "Symbol.h"

using namespace std;

typedef map<string,double> Vars;


class Expression  : public Symbol{
   public:
      Expression(TokenSymbol id_symb):Symbol(id_symb){};
      //Expression():Symbol(E){};
      virtual ~Expression(){};
      virtual void print(){};
      virtual double Evaluation(const Vars & variables) {return 0;};
};

class Valeur: public Expression {
   // une expression composée uniquement d'une valeur double
   public:
      Valeur(int val):Expression(VAL),valeur(val){};
      Valeur(double val):Expression(VAL),valeur(val){};
      ~Valeur(){};
      double Evaluation(const Vars & variables);
      void print();
   protected:
      double valeur;
};

class Variable: public Expression {
   // une expression composée uniquement d'une variable
   public:
      Variable(string n):Expression(VAR),nom(n){};
      ~Variable(){};
      double Evaluation(const Vars & variables);
      void print();
   protected:
      string nom;
};

class Parentese: public Expression {
   public:
      Parentese(Expression * expr):Expression(OPENBY),expression(expr){};
      ~Parentese(){delete expression;};
      void print();
      virtual double Evaluation(const Vars & variables) ;
   protected:
      Expression *expression;
};

class OperateurBinaire: public Expression { // MINUS MULT DIVIDE PLUS
   // un opérateur binaire générique, pour l'implémenter, il faut
   // implémenter la méthode operation()
   public:
      OperateurBinaire(TokenSymbol id_symb,Expression * g, Expression * d):Expression(id_symb),gauche (g),droite (d){};
      ~OperateurBinaire();
      double Evaluation(const Vars & variables);
      virtual void print();
   protected:
      virtual double operation(double g, double d) = 0;
      void printOperator(TokenSymbol id_symb);
      Expression * gauche;
      Expression * droite;
};

class OperateurPlus: public OperateurBinaire {
   public:
      OperateurPlus(Expression * g, Expression * d):OperateurBinaire(PLUS,g,d){};
      ~OperateurPlus(){};
      void print();
   protected:
      double operation(double g, double d);
};

class OperateurMoins: public OperateurBinaire {
   public:
      OperateurMoins(Expression * g, Expression * d):OperateurBinaire(MINUS,g,d){};
      ~OperateurMoins(){};
      void print();
   protected:
      double operation(double g, double d);
};

class OperateurDiv: public OperateurBinaire {
   public:
      OperateurDiv(Expression * g, Expression * d):OperateurBinaire(DIVIDE,g,d){};
      ~OperateurDiv(){};
      void print();
   protected:
      double operation(double g, double d);
};

class OperateurMul: public OperateurBinaire {
   public:
      OperateurMul(Expression * g, Expression * d):OperateurBinaire(MULT,g,d){};
      ~OperateurMul(){};
      void print();
   protected:
      double operation(double g, double d);
};



#endif
