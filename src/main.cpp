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
          // fileInput +='\n';
		}
		myfile.close();
	}	else	{
		cerr << "Error reading the file" << endl;
	}
    DEBUG_STDOUT(fileInput << endl);
	return fileInput;
} 

int main_x()
{
	// Create Lexer instance with it
	Lexer lex = Lexer(getFileContent_x("./bin/example.txt"));

	if(lex.analyseAll())	{
		DEBUG_STDOUT("Success! " << lex.tokensList.size() << " tokens found." << endl;)
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

    lexer.analyseAll();

    Programme programme;
    Automaton automate(&lexer,&programme);

    error = automate.read();
    if(!error) return 1;


    /*  -a argument: Static analysis    */
    if (argParser->getStaticAnalysisFlag())
    {
        //Make necessary to do a static analysis
        programme.analyse();
    }


    /*  -o argument: Optimization   */
    if (argParser->getOptimizeFlag())
    {
        //Make necessary to transform / optimize code
        //cerr << "Optimization" << endl;
        Programme pr2;
        error =  programme.optimize(&pr2);
        if(!error)
        {
            cerr << "erreur optimisation  " << endl;
            return 1;
        }

        if (argParser->getPrintFlag())  cout << pr2;
    }

    /*	-e argument: Execution	*/
    if (argParser->getExecutionFlag())
    {
    	//Make necessary to execute program
    	//cerr << "execute" << endl;
	    error = programme.execute();
    }

    /*  -p argument: Print code */
    if (argParser->getPrintFlag() && !argParser->getOptimizeFlag())
    {
        //Make necessary to print the code
        //cerr << "print" << endl;
        cout << programme ;
    }

    return !error;
}
