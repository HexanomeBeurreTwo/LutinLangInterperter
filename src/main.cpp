#include "Debug.h"
#include "Programme.h"
#include "ArgParser.h"
#include "Lexer.h"
#include "Automaton.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


string getFileContent_x(string pathfile)
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
    DEBUG_STDOUT(fileInput << endl);
	return fileInput;
} 

int main_x()
{
	// Create Lexer instance with it
	Lexer lex = Lexer(getFileContent_x("./bin/example.txt"));

	if(lex.analyseAll())	{
		cout << "Success! " << lex.tokensList.size() << " tokens found." << endl;
	}

	return 0;
}

int main(int argc, char const *argv[])
{
    string file;
    int error = 0;
    // traiter les option -e -o -p ... et récuperer le nom du fichier
    ArgParser* argParser = new ArgParser(argc, argv);

    if (argParser->getError())
    {
    	return 1;
    }

    file = argParser->getFilePath();
    Lexer lexer(getFileContent_x(file));

    Programme programme;
    Automaton automate(&lexer,&programme);

    // error = automate.read();

    /*	-p argument: Print code	*/
    if (argParser->getPrintFlag())
    {
    	//Make necessary to print the code
   		cout << programme ;
    }

    /*	-e argument: Execution	*/
    if (argParser->getExecutionFlag())
    {
    	//Make necessary to execute program
	    error = programme.execute();
    }

    /*	-a argument: Static analysis	*/
    if (argParser->getStaticAnalysisFlag())
    {
    	//Make necessary to do a static analysis
    }

    /*	-o argument: Optimization	*/
    if (argParser->getOptimizeFlag())
    {
    	//Make necessary to transform / optimize code
		Programme pr2;
		error =  programme.optimize(&pr2);
		if(!error)
		{
			cerr << "erreur optimisation  " << endl;
			return 1;
		}

		cout << pr2 ;
    }

    return error;
}
