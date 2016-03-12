#include "Programme.h"
//#include "Lexer.h"
//#include "Automaton.h"


int main()
{
    string file;
    bool error;
    // traiter les option -e -o -p ... et récuperer le nom du fichier

    // Lexer lexer(file);
    Programme programme;
    // Automaton automate(lexer,programme);
    // error = automate.read();
    // traiter erreur lexical selon de error
    // si l'option est -e faire
    error = programme.execute();
    // traiter erreur excution selon error
    //sinon si l'option est -a faire
    programme.print();
    //sion si l'optoin est -o faire
    programme.optimize();
}
