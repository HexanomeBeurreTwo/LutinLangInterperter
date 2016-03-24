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
//                 DEBUG_STDOUT("Success! " << lex.tokensList.size() << " tokens found." << endl);
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
			  //DEBUG_STDOUT(tmp << endl);
			}
			myfile.close();
        } else  {
                DEBUG_STDOUT("Error reading the file" << endl);
        }

		cout <<"Analyse du fichier " << endl
			 <<"#####" << endl 
			 <<   tmp << endl
			 <<"#####" << endl;
		
		//string* fileInput = new string(tmp);
        return  tmp;
}



int main_u()    
{
    string file("./bin/example.lt");
	
    bool success;
    // traiter les option -e -o -p ... et recuperer le nom du fichier

	//string* contentFile = getFileContent(file);
	string  tmp =  "var a,e,b;";
			tmp += "const c = 44.1;";
			tmp += "var k; ";
			//tmp += "b := 2;";
			tmp += "lire e;";
			tmp += "ecrire e;";
			tmp += "a := (c+c)*3-5+0+1*e;";
			tmp +=  "ecrire (e+u+0)*1-0;";
			tmp +=  "ecrire (7*e);";
			
			//tmp += "ecrire a;";
			//tmp += "ecrire a*b;";
			//tmp += "a := b;";
			//tmp += "ecrire a;";	
	
	//tmp = "sdf var F";
	//tmp = getFileContent(file);
	
	
	DEBUG_STDOUT("~~~~~INPUT FILE~~~~~~~~" << endl
		 << 	   tmp 		  << endl
		 << "~~~~~~~~~~~~~~~~~~~~~~~" << endl);

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
	
	DEBUG_STDOUT("~~~~~~~ANALYSE~~~~~~~"<< endl);
	programme.analyse();
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	
	DEBUG_STDOUT("~~~~~~~EXECUTION~~~~~~~"<< endl);
    success = programme.execute();
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
		return 1;
	}
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	
	DEBUG_STDOUT("~~~~~~~OPTIMISATION~~~~~"<< endl);
    Programme prog_opz;
    success =  programme.optimize(&prog_opz);
    if(!success)
	{
		cerr << "erreur optimisation  " << endl;
		return 1;
	} else{
		DEBUG_STDOUT(prog_opz );
	}
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	
	DEBUG_STDOUT("~~~~~~~EXECUTION~~~~~~~"<< endl);
    success = prog_opz.execute();
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
		return 1;
	}
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	

	
	
    return success;
}
