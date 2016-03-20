#include "Programme.h"
#include "Lexer.h"
#include "Automaton.h"


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string* getFileContent(string pathfile);
int main_x()
{
		string file = "./bin/example.lt";
        // Create Lexer instance with it
		string* cotentFile = getFileContent(file);
		Lexer lex(*cotentFile);

        if(lex.analyseAll())    {
                cout << "Success! " << lex.tokensList.size() << " tokens found." << endl;
        }

        return 0;
}


ostream& operator<< (ostream& os, const ValuableToken& t){
        switch(t.token){
                case VAR : os << "---VAR--" << endl; break;
                case CONST : os << "---CONST--" << endl; break;
                case AFFECT : os << "---AFFECT--" << endl; break;
                case EQUAL : os << "---EQUAL--" << endl; break;
                case SEP : os << "---SEP--" << endl; break;
                case WRITE : os << "---WRITE--" << endl; break;
                case READ : os << "---READ--" << endl; break;
                case END : os << "---END--" << endl; break;
                case ID : os << "---ID--" << endl; break;
                case VAL : os << "---VAL--" << endl; break;
                case MINUS : os << "---MINUS--" << endl; break;
                case OPENBY : os << "---OPENBY--" << endl; break;
                case CLOSEBY : os << "---CLOSEBY--" << endl; break;
                case MULT : os << "---MULT--" << endl; break;
                case DIVIDE : os << "---DIVIDE--" << endl; break;
                case PLUS : os << "---PLUS--" << endl; break;
                case INVALID : os << "---INVALID--" << endl; break;
                case END_OF_FILE : os << "---END_OF_FILE--" << endl; break;

                default : os << "Indefined !" << endl;
        }
        return os;
}


string* getFileContent(string pathfile)
{
        string line ;
        string tmp;
		string tmp1;
        ifstream myfile;
        myfile.open(pathfile);
        if (myfile)
        {
			while ( getline (myfile,line) )
			{
			  cout << line << endl;
			  tmp1 = tmp;
			  tmp = tmp1 + line;
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
		
		string* fileInput = new string(tmp);
        return  fileInput;
}



int main()    
{
    string file = "./bin/example.lt";
    bool success;
    // traiter les option -e -o -p ... et r▒cuperer le nom du fichier

	string* contentFile = getFileContent(file);
    Lexer lexer(*contentFile);
    lexer.analyseAll();
    Programme programme;
    Automaton automate(&lexer,&programme);
    success = automate.read();
	if(!success)
	{
		cerr << "erreur Syntaxique : construction automate " << endl;
	}
    // traiter erreur lexical et syntaxique selon de error
    // si l'option est -e faire
    success = programme.execute();
	if(!success)
	{
		cerr << "erreur Symentique : execution programme " << endl;
	}
    // traiter erreur excution selon error
    //sinon si l'option est -a faire
    cout << programme ;
    //sion si l'optoin est -o faire
    //programme.optimize();

    return success;
}
