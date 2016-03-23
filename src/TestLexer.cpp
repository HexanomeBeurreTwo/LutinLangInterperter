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
			  cout << line << endl;
			  tmp +=  line;
			  //cout << tmp << endl;
			}
			myfile.close();
        } else  {
                cout << "Error reading the file" << endl;
        }

		cout <<"Analyse du fichier " << endl
			 <<"#####" << endl 
			 <<   tmp << endl
			 <<"#####" << endl;
		
		//string* fileInput = new string(tmp);
        return  tmp;
}



int main()    
{
    string file("./bin/example.lt");
	
    bool success;
    // traiter les option -e -o -p ... et recuperer le nom du fichier

	//string* contentFile = getFileContent(file);
	string  tmp =  "var a,e,b;";
			tmp += "const c = 44.1;";
			
			//tmp += "b := 2;";
			tmp += "lire e;";
			tmp += "ecrire e;";
			tmp += "a := (c+c)*3-5+0+1*e;";
			tmp +=  "ecrire (e+0)*1-0;";
			tmp +=  "ecrire (7*e);";
			//tmp += "ecrire a;";
			//tmp += "ecrire a*b;";
			//tmp += "a := b;";
			//tmp += "ecrire a;";	
	
	//tmp = "sdf var F";
	//tmp = getFileContent(file);
	
	
	cout << "~~~~~INPUT FILE~~~~~~~~" << endl
		 << 	   tmp 		  << endl
		 << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;

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
	
	cout << "~~~~~~~AFFICHAGE~~~~~~~"<< endl;
    cout << programme ;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	
	cout << "~~~~~~~EXECUTION~~~~~~~"<< endl;
    success = programme.execute();
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
		return 1;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	
	cout << "~~~~~~~OPTIMISATION~~~~~"<< endl;
    Programme prog_opz;
    success =  programme.optimize(&prog_opz);
    if(!success)
	{
		cerr << "erreur optimisation  " << endl;
		return 1;
	} else{
		cout << prog_opz ;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	
	cout << "~~~~~~~EXECUTION~~~~~~~"<< endl;
    success = prog_opz.execute();
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
		return 1;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	
    return success;
}
