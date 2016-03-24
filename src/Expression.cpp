#include "Expression.h"
#include <iostream>
#include "Declaration.h"
#include "DeclarationConst.h"
#include "DeclarationVariable.h"
#include "Symbol.h"

using namespace std;


Expression* Expression::get_ptimized_expression(Declrs & variables) {
  Expression* res;
  res = get_ptimized_expr(variables);
  return res;
}

//####################################### VALEUR

Expression* Valeur::get_ptimized_expr( Declrs & variables) 
{
	return new Valeur(valeur);	
}

bool Valeur::Evaluation(double *res, Declrs & variables) {
   *res = this->valeur;
   return true;
}

bool Valeur::analyse(double* res,Declrs & variables) 
{
	//*res = this->valeur;
	return true; 
 }

void Valeur::print(ostream& os) const{
    os <<""<<valeur<<"";
}


//####################################### VARIABLE

Expression* Variable::get_ptimized_expr( Declrs & variables) 
{

	double value;
	Expression* exp;
	
	if(Evaluation(&value,variables)) 
	{
		exp = new Valeur(value);
	}
	
	exp = new Variable(nom);
	
	return exp;
}

bool Variable::Evaluation(double *res,Declrs & variables) {
   Declrs::iterator var = variables.find(nom);

   if( var!=variables.end() && (var->second)->is_initialized() ) 
   {
      *res = (var->second)->get_valeur();
	  (var->second) -> set_used();
	  return true;
   }
   return false;
}

bool Variable::analyse(double *res,Declrs & variables) {
   Declrs::iterator var = variables.find(nom);
   if(var==variables.end()) 
   {
	   Declaration * dec = new DeclarationVariable(nom);
	   dec->set_undeclared();
	   dec->set_used();
	   variables[nom] = dec ;
	   return false;
	   
   }
   (var->second)-> set_used();
   
   return true;
}

void Variable::print(ostream& os) const{
    os <<""<<nom<<"";
}

//####################################### OperateurBinaire


Expression* OperateurBinaire::get_ptimized_expr( Declrs & variables) 
{
	double valueG,valueD;
	Expression* gaucheOpz,*droiteOPZ;
	
	
	if(gauche->Evaluation(&valueG,variables)) 
	{
		gaucheOpz =  new Valeur(valueG);
	}else {
		gaucheOpz = gauche -> get_ptimized_expr(variables) ; 
	}
	
	if(droite->Evaluation(&valueD,variables)) 
	{
		droiteOPZ =  new Valeur(valueD);
	}else {
		droiteOPZ = droite-> get_ptimized_expr(variables) ;
	}
	
	
	if((valueG ==0 || valueD ==0) && (this->ident == PLUS || this->ident == MINUS))
	{
		if(valueG ==0) return droiteOPZ;
		else return gaucheOpz;
		
	}
	
	if((valueG ==1 || valueD ==1) && (this->ident == MULT || this->ident == DIVIDE))
	{
		if(valueG ==1) return droiteOPZ;
		else return gaucheOpz;
	
	}	

	return create_OperateurBinaire(gaucheOpz, droiteOPZ);
		
}


OperateurBinaire::~OperateurBinaire() {
   delete gauche;
   delete droite;
}

bool OperateurBinaire::Evaluation(double *res, Declrs & variables) {
   double valg,vald;
   
   if( !gauche->Evaluation(&valg,variables) ||
	   !droite->Evaluation(&vald,variables) )
   {
		
		return false;
   }
   *res = operation(valg,vald);
   
   return true;
}

bool OperateurBinaire::analyse(double *res, Declrs & variables) {
   double valg,vald;
   return gauche->analyse(&valg,variables) && droite->analyse(&vald,variables) ;
 
}

void OperateurBinaire::print(ostream& os) const
{
    os << (*gauche) ;
    printOperator(os);
    os << (*droite);
}




//####################################### Parentese

Expression* Parentese::get_ptimized_expr( Declrs & variables) 
{
	double value;
	Expression* opz_expr ;

	
	if(Evaluation(&value,variables)) 
	{
		opz_expr = new Parentese (new Valeur(value));
	}else {
		opz_expr = new Parentese (expression->get_ptimized_expr( variables) );
	}
	
	return opz_expr;
}

bool Parentese::Evaluation(double *res, Declrs & variables) {
	
	bool b =  expression->Evaluation(res,variables);
	
	return b;
}

bool Parentese::analyse(double *res, Declrs & variables) {
	
	return expression->analyse(res,variables);
}

void Parentese::print(ostream& os) const{
    os << "(" << (*expression) << ")" ;

}

//####################################### PLUS MIONS DIV MUL

double OperateurPlus::operation(double g, double d) {
   return g+d;
}

void OperateurPlus::printOperator(ostream& os) const
{
    os << " + ";
}

Expression* OperateurPlus::create_OperateurBinaire(Expression* g, Expression* d)
{
	return new OperateurPlus(g,d);
}


double OperateurMoins::operation(double g, double d) {
   return g-d;
}

void OperateurMoins::printOperator(ostream& os) const
{
    os << " - ";
}

Expression* OperateurMoins::create_OperateurBinaire(Expression* g, Expression* d)
{
	return new OperateurMoins(g,d);
    
}

double OperateurDiv::operation(double g, double d) {
   return g/d;
}

void OperateurDiv::printOperator(ostream& os) const
{
    os << " / ";
}

Expression* OperateurDiv::create_OperateurBinaire(Expression* g, Expression* d)
{
	return new OperateurDiv(g,d);
}

double OperateurMul::operation(double g, double d) {
   return g*d;
}

void OperateurMul::printOperator(ostream& os) const
{
    os << " * ";
}

Expression* OperateurMul::create_OperateurBinaire(Expression* g, Expression* d)
{
   return new OperateurMul(g,d);
}







