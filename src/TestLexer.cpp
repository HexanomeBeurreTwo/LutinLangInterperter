#include "Programme.h"
#include "Lexer.h"
#include "Automaton.h"


#include <iostream>
#include <string>
#include <fstream>
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



int main_o()    
{
    string file("./bin/example.lt");
    bool success;
    // traiter les option -e -o -p ... et recuperer le nom du fichier

    cout << "Test" << endl;
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
    // traiter erreur excution selon error
    //sinon si l'option est -a faire
	cout << "~~~~~~~AFFICHAGE~~~~~~~"<< endl;
    cout << programme ;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	// traiter erreur lexical et syntaxique selon de error
    // si l'option est -e faire
	cout << "~~~~~~~EXECUTION~~~~~~~"<< endl;
    success = programme.execute();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
		return 1;
	}
    //sion si l'optoin est -o faire
    //programme.optimize();

    return success;
}
