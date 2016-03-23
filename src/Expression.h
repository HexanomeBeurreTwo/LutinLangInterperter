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
      virtual Expression* get_ptimized_expr(Declrs & variables) = 0;
	  
};

class Valeur: public Expression {
   // une expression composée uniquement d'une valeur double
   public:
      Valeur(int val):Expression(VAL),valeur(val){};
      Valeur(double val):Expression(VAL),valeur(val){};
      ~Valeur(){};
      bool Evaluation(double* res,const Declrs & variables);
      void print(ostream& os) const;
      Expression* get_ptimized_expr( Declrs & variables) ;
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
      Expression* get_ptimized_expr( Declrs & variables) ;
   protected:
      string nom;
};

class Parentese: public Expression {
   public:
      Parentese(Expression * expr):Expression(OPENBY),expression(expr){};
      ~Parentese(){delete expression;};
      void print(ostream& os) const;
      bool Evaluation(double* res,const Declrs & variables);
      Expression* get_ptimized_expr( Declrs & variables) ;
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
      virtual Expression* get_ptimized_expr( Declrs & variables) ;
   protected:
      virtual double operation(double g, double d) = 0;
      virtual void printOperator(ostream& os ) const = 0;
	  virtual Expression* create_OperateurBinaire(Expression* g, Expression* d)=0;
      Expression * gauche;
      Expression * droite;
};

class OperateurPlus: public OperateurBinaire {
   public:
      OperateurPlus(Expression * g, Expression * d):OperateurBinaire(PLUS,g,d){};
      ~OperateurPlus(){};
   protected:
      double operation(double g, double d);
	  void printOperator(ostream& os ) const ;
	  Expression* create_OperateurBinaire(Expression* g, Expression* d);
	 
};

class OperateurMoins: public OperateurBinaire {
   public:
      OperateurMoins(Expression * g, Expression * d):OperateurBinaire(MINUS,g,d){};
      ~OperateurMoins(){};
   protected:
      double operation(double g, double d);
	  void printOperator(ostream& os ) const ;
	  Expression* create_OperateurBinaire(Expression* g, Expression* d);
};

class OperateurDiv: public OperateurBinaire {
   public:
      OperateurDiv(Expression * g, Expression * d):OperateurBinaire(DIVIDE,g,d){};
      ~OperateurDiv(){};
   protected:
      double operation(double g, double d);
	  void printOperator(ostream& os ) const ;
	  Expression* create_OperateurBinaire(Expression* g, Expression* d);
};

class OperateurMul: public OperateurBinaire {
   public:
      OperateurMul(Expression * g, Expression * d):OperateurBinaire(MULT,g,d){};
      ~OperateurMul(){};
   protected:
      double operation(double g, double d);
	  void printOperator(ostream& os ) const ;
	  Expression* create_OperateurBinaire(Expression* g, Expression* d);
};



#endif
