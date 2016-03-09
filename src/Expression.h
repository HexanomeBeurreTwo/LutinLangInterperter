#ifndef _EXPR_H
#define _EXPR_H

#include <string>

#include "Instruction.h"






class Expression  : public Instruction{
   public:
      Expression(Tokens id_symb):Instruction(id_symb){};
      //Expression():Instruction(E){};
      virtual ~Expression(){};
      virtual void print() = 0;
      virtual double Evaluation(const Declrs & variables) = 0;
};

class Valeur: public Expression {
   // une expression composée uniquement d'une valeur double
   public:
      Valeur(int val):Expression(VAL),valeur(val){};
      Valeur(double val):Expression(VAL),valeur(val){};
      ~Valeur(){};
      double Evaluation(const Declrs & variables);
      void print();
   protected:
      double valeur;
};

class Variable: public Expression {
   // une expression composée uniquement d'une variable
   public:
      Variable(string n):Expression(VAR),nom(n){};
      ~Variable(){};
      double Evaluation(const Declrs & variables);
      void print();
      string get_nom(){return nom;}
   protected:
      string nom;
};

class Parentese: public Expression {
   public:
      Parentese(Expression * expr):Expression(OPENBY),expression(expr){};
      ~Parentese(){delete expression;};
      void print();
      virtual double Evaluation(const Declrs & variables) ;
   protected:
      Expression *expression;
};

class OperateurBinaire: public Expression { // MINUS MULT DIVIDE PLUS
   // un opérateur binaire générique, pour l'implémenter, il faut
   // implémenter la méthode operation()
   public:
      OperateurBinaire(Tokens id_symb,Expression * g, Expression * d):Expression(id_symb),gauche (g),droite (d){};
      ~OperateurBinaire();
      double Evaluation(const Declrs & variables);
      void print();
   protected:
      virtual double operation(double g, double d) = 0;
      void printOperator(Tokens id_symb);
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
