#include "Programme.h"
#include "Lexer.h"
#include "Automaton.h"


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    string fileInput = "";
	string line = "";
	// Read file
	ifstream myfile;
	myfile.open("./bin/Debug/example.txt");
	if (myfile)
	{
		while ( getline (myfile,line) )
		{
		  fileInput += line;
		}
		myfile.close();
	}	else	{
		cout << "Error reading the file" << endl;
	}

	// Create Lexer instance with it
	Lexer lex = Lexer(fileInput);

	if(lex.analyseAll())	{
		cout << "Success! " << lex.tokensList.size() << " tokens found." << endl;
	}

	return 0;
}


int main_X()
{
    string file;
    bool error;
    // traiter les option -e -o -p ... et récuperer le nom du fichier

    Lexer lexer("file_contenent");
    Programme programme;
    Automaton automate(&lexer,&programme);
    error = automate.read();
    // traiter erreur lexical et syntaxique selon de error
    // si l'option est -e faire
    error = programme.execute();
    // traiter erreur excution selon error
    //sinon si l'option est -a faire
    programme.print();
    //sion si l'optoin est -o faire
    programme.optimize();

    return error;
}
