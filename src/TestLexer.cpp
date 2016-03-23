#include "Debug.h"
#include "Programme.h"
#include "Lexer.h"
#include "Automaton.h"


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string getFileContent(string pathfile);
// int main_x()
// {
// 		string file = "./bin/example.lt";
//         // Create Lexer instance with it
// 		string* cotentFile = getFileContent(file);
// 		Lexer lex(*cotentFile);

//         if(lex.analyseAll())    {
//                 cout << "Success! " << lex.tokensList.size() << " tokens found." << endl;
//         }

//         return 0;
// }


string getFileContent(string pathfile)
{
        string line ;
        string tmp;
        ifstream myfile;
        myfile.open(pathfile);
        if (myfile)
        {
			while ( getline (myfile,line) )
			{
			  DEBUG_STDOUT(line << endl);
			  tmp +=  line;
			  //cout << tmp << endl;
			}
			myfile.close();
        } else  {
                cerr << "Error reading the file" << endl;
        }

		DEBUG_STDOUT("Analyse du fichier " << endl
			 <<"#####" << endl 
			 <<   tmp << endl
			 <<"#####" << endl);
		
		//string* fileInput = new string(tmp);
        return  tmp;
}



int main_o()    
{
    string file("./bin/example.lt");
    bool success;
    // traiter les option -e -o -p ... et recuperer le nom du fichier

    DEBUG_STDOUT( "Test" << endl);
	//string* contentFile = getFileContent(file);
	string  tmp =  "var a,b;";
			tmp += "const c = 44.1;";
			tmp += "lire b;";
			tmp += "a := (c)*3-5;";
			tmp += "ecrire a;";
			tmp += "ecrire a*b;";
			tmp += "a := b;";
			tmp += "ecrire a;";	
	
	//tmp = "sdf var F";
	//tmp = getFileContent(file);
    Lexer lexer(tmp);  
    lexer.analyseAll();
    Programme programme;
    Automaton automate(&lexer,&programme);
    success = automate.read();
	if(!success)
	{
		cerr << "erreur Syntaxique : construction automate " << endl;
		return 1;
	}
	
	DEBUG_STDOUT("~~~~~~~AFFICHAGE~~~~~~~"<< endl);
    DEBUG_STDOUT(programme );
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	
	DEBUG_STDOUT("~~~~~~~EXECUTION~~~~~~~"<< endl);
    success = programme.execute();
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
		return 1;
	}
    //programme.optimize();

    return success;
}
