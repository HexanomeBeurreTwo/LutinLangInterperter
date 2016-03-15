
#include "Programme.h"
#include "Lexer.h"
#include "Automaton.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string getFileContent(string pathfile)
{
	string line = "";
	string fileInput = "";
	ifstream myfile;
	myfile.open(pathfile);
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

	return 	fileInput;
}

int main_x()
{
	// Create Lexer instance with it
	Lexer lex = Lexer(getFileContent("./bin/example.txt"));

	if(lex.analyseAll())	{
		cout << "Success! " << lex.tokensList.size() << " tokens found." << endl;
	}

	return 0;
}

int main(int argc, char const *argv[])  {
    string file = "./bin/example.txt";
    bool error;
    // traiter les option -e -o -p ... et récuperer le nom du fichier

    Lexer lexer(getFileContent(file));
    Programme programme;
    Automaton automate(&lexer,&programme);
    error = automate.read();
    // traiter erreur lexical et syntaxique selon de error
    // si l'option est -e faire
    error = programme.execute();
    // traiter erreur excution selon error
    //sinon si l'option est -a faire
    cout << programme ;
    //sion si l'optoin est -o faire
    programme.optimize();

    return error;
}
