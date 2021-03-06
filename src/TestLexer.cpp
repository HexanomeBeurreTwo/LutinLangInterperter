#include "Debug.h"
#include "Programme.h"
#include "Lexer.h"
#include "Automaton.h"


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string getFileContent(string pathfile);


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
			}
			myfile.close();
        } else  {
                DEBUG_STDOUT("Error reading the file" << endl);
        }

		DEBUG_STDOUT("Analyse du fichier " << endl
			 <<"#####" << endl 
			 <<   tmp << endl
			 <<"#####" << endl);
		
        return  tmp;
}




int main_u()    
{
    string file("./bin/example.lt");
	
    bool success;
    // traiter les option -e -o -p ... et recuperer le nom du fichier

    DEBUG_STDOUT( "Test" << endl);
	//string* contentFile = getFileContent(file);
	string  tmp = "var a;const b=10;lire a;ecrire (a-0)*1+0+0/b;";
	//tmp =  "var   a,j,e,h,s;";
	//tmp += "const c = 44.1;";
	// tmp += "b := 2;";
	// tmp += "lire e;";
	// tmp += "ecrire e;";
	//tmp += "a := (c + c )*3- 5+0+1*e;";
	// tmp += "h := 4;";
	// tmp += "a := h+c+s+j;";
	// tmp +=  "ecrire (e-s+0)*1- 0;";
	// tmp +=  "ecrire (7*e);";
	//tmp += "e :=-6 * 2;";
	// tmp += "ecrire e;";
	//tmp += "ecrire 5--3;";
			
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
	} else 
	{
		DEBUG_STDOUT( "Automate ok!" << endl );
	}
	
	DEBUG_STDOUT("~~~~~~~AFFICHAGE~~~~~~~"<< endl
	<< programme 
	<< "~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	
	DEBUG_STDOUT("~~~~~~~ANALYSE~~~~~~~~~"<< endl);
	success = programme.analyse() ;
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
	if(!success)
	{
		cerr << "ABORT : Des erreurs ont survenus. " << endl;
		return 1;
	}
	
	
	DEBUG_STDOUT("~~~~~~~EXECUTION~~~~~~~"<< endl);
    success = programme.execute();
	DEBUG_STDOUT("~~~~~~~~~~~~~~~~~~~~~~~"<< endl);
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
		cout << prog_opz ;
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
