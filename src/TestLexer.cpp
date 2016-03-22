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
	string  tmp =  "var a,e;";
			tmp += "const c = 44.1;";
			tmp += "lire e;";
			tmp += "a := (c+c)*3-5;";
			tmp += "ecrire a;";
			tmp += "ecrire a*c;";
			tmp += "e := c+a;";
			tmp += "ecrire e;";	
	
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
	
	cout << "~~~~~~~AFFICHAGE~~~~~~~"<< endl;
    cout << programme ;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	
	cout << "~~~~~~~EXECUTION~~~~~~~"<< endl;
    success = programme.execute();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
		return 1;
	}
    
    Programme pr2;
    success =  programme.optimize(&pr2);
    if(!success)
	{
		cerr << "erreur optimisation  " << endl;
		return 1;
	} else{
		cerr << "optimisation reussie  " << endl;
		cout << pr2 ;
	}

    return success;
}
