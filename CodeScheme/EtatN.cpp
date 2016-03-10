#include "EtatN.h"

EtatN::EtatN() : State() { }

bool EtatN::transition(Automate *automate, Symbole *s) {
  switch ( t->getTokenType() ) {
    case TokenType::ENDOFFILE :
  	  //
      return true;
    default:
      return false;
  }
  return false;
}
