
//
//  LutinLangInterperter
//  Lexer.cpp
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "Lexer.h"
using boost::regex;

// Regexs
const char keyword_str[] = "^(const |var |ecrire |lire )";
const char identifier_str[] = "^([a-zA-Z][a-zA-Z0-9]*)";
const char number_str[] =  "^([0-9]*\\.?[0-9]+)";
const char operators_str[] = "^(\\+|-|\\*|\\/|\\(|\\)|;|=|,|:=)";

const regex keyword(keyword_str);
const regex identifier(identifier_str); 
const regex number(number_str);
const regex operators(operators_str);

ValuableToken Lexer::getCurrentToken()	{
	return lastTokenFetched;
}

ValuableToken Lexer::getNext()	{
	lastTokenFetched = *(tokensList[cursor]);
	//consumeNext();// à enlever apres avoir fini les tests
	return lastTokenFetched;
}

bool Lexer::consumeNext()	{
	//If INVALID
	if ( hasNext() ) //&& tokensList[cursor+1]->token != INVALID)
	{
		cursor++;
		return true;
	}
	return false;
}

bool Lexer::hasNext()	{
	return (cursor +1) < tokensList.size();
}

void Lexer::leftTrim(string &inputString)	{
	int charToEraseNum = 0;
	bool somethingToErase = true;

	while(somethingToErase)	{
		switch(inputString.at(charToEraseNum))	{
			case ' ':
				charToEraseNum++;
				column++;
				break;
			case '\n':
				charToEraseNum++;
				column = 0;
				line++;
				break;
			default:
				somethingToErase = false;
				break;
		}
	}
	inputString.erase(0, charToEraseNum);
}

bool Lexer::analyseAll()	{
	string inputToAnalyse = fileLines;
	int numOfCharToRemove;
	// cout << "Analysis begin..." << endl;

	do
	{
		leftTrim(inputToAnalyse);
		// cout << "[" << inputToAnalyse << "] @" << line+1 << "," << column+1 << endl;

		ValuableToken *tokenFetched = new ValuableToken();
		tokensList.push_back(tokenFetched);
		string foundKeyword;
		numOfCharToRemove = 0;
		analyseNext(inputToAnalyse, tokensList.back(), foundKeyword, numOfCharToRemove);
		
		// symbolsList.push_back(new Symbol(...))
		
		if (tokenFetched->token == INVALID)	{	return false;	}

		// Remove word from input
		inputToAnalyse.erase(0, numOfCharToRemove);

		//Cursor update
		column += numOfCharToRemove;
	} while (inputToAnalyse.length() > 0);
	ValuableToken *eof = new ValuableToken();
	eof->token = END_OF_FILE;
	tokensList.push_back(eof);
	// cout << "Analysis ended..." << endl;
	return true;
}

bool Lexer::analyseNext(string inputToAnalyse, ValuableToken *tokenFetched, string &foundKeyword, int &size)	{
	boost::match_results<string::const_iterator> results;
	if (regex_search(inputToAnalyse, results, keyword))	{
		string strFetched = results[0].str();
		size = (results[0].str()).size();
		tokenFetched->value = (void*) new string(strFetched);

		string reverseConversion = *((string*)tokenFetched->value); //reverseConversion == keyboardFetched
		char firstChar = reverseConversion[0];
		switch(firstChar)	{
			case 'c':
				// cout << "It's a const!" << endl;
				tokenFetched->token = CONST;
				break;
			case 'v':
				// cout << "It's a var!" << endl;
				tokenFetched->token = VAR;
				break;
			case 'e':
				// cout << "It's a ecrire!" << endl;
				tokenFetched->token = WRITE;
				break;
			case 'l':
				// cout << "It's a lire!" << endl;
				tokenFetched->token = READ;
				break;
			default:
				// cout << "It's an error!" << endl;
				tokenFetched->token = INVALID;
				return false;
				break;
		}
	}
	else if (regex_search(inputToAnalyse, results, identifier))	{
		string strFetched = results[0].str();
		size = (results[0].str()).size();
		tokenFetched->value = (void*) new string(strFetched);

		// cout << "It's an identifier : " << *((string*)tokenFetched->value) << "!" << endl;
		tokenFetched->token = ID;
	}
	else if (regex_search(inputToAnalyse, results, number))	{
		// int numberFetched = stoi(results[0].str());
		double numberFetched = stod(results[0].str());
		size = (results[0].str()).size();

		// tokenFetched->value = (void*) new int(numberFetched);
		tokenFetched->value = (void*) new double(numberFetched);
		// cout << "It's a number : " << *((int*)tokenFetched->value) << "!" << endl;
		tokenFetched->token = VAL;
	}
	else if (regex_search(inputToAnalyse, results, operators))	{
		string strFetched = results[0].str();
		size = (results[0].str()).size();
		tokenFetched->value = (void*) new string(strFetched);

		string reverseConversion = *((string*)tokenFetched->value); //reverseConversion == keyboardFetched
		char firstChar = reverseConversion[0];
		switch(firstChar)	{
			case '+':
				// cout << "It's a plus!" << endl;
				tokenFetched->token = PLUS;
				break;
			case '-':
				// cout << "It's a minus!" << endl;
				tokenFetched->token = MINUS;
				break;
			case '*':
				// cout << "It's a multiply!" << endl;
				tokenFetched->token = MULT;
				break;
			case '/':
				// cout << "It's a divide!" << endl;
				tokenFetched->token = DIVIDE;
				break;
			case '(':
				// cout << "It's a open parenthesis!" << endl;
				tokenFetched->token = OPENBY;
				break;
			case ')':
				// cout << "It's a close parenthesis!" << endl;
				tokenFetched->token = CLOSEBY;
				break;
			case ';':
				// cout << "It's an end line!" << endl;
				tokenFetched->token = END;
				break;
			case '=':
				// cout << "It's an equal!" << endl;
				tokenFetched->token = EQUAL;
				break;
			case ',':
				// cout << "It's a separator!" << endl;
				tokenFetched->token = SEP;
				break;
			case ':':
				// cout << "It's an affectation!" << endl;
				tokenFetched->token = AFFECT;
				break;
			default:
				// cout << "It's an error!" << endl;
				tokenFetched->token = INVALID;
				return false;
				break;      
		} 
	}
	else {
		// cout << "It's an error!" << endl;
		size = 0;
		tokenFetched->value = NULL;
		tokenFetched->token = INVALID;
		return false;
	}
	return true;
}



Lexer::Lexer(string inputString) : fileLines(inputString)	{

	vector<ValuableToken> tokensList;
	lastTokenFetched.token = INVALID;
	cursor = 0;
	line = 0;
	column = 0;
	cout << "Contenu du fichier : " << inputString << endl;
}

Lexer::~Lexer()	{
	// cout << "Destructor..." << endl;
	int size = tokensList.size();
	int cpt = 0;
	while(cpt < size)	{
		ValuableToken *valTok = tokensList.back();
		if(valTok->token == VAL)	{
			delete(static_cast<int*>(valTok->value));
		}
		else if(valTok->token != VAL)	{
			delete(static_cast<string*>(valTok->value));
		}

		// Delete ValuableToken
		delete valTok;
		cpt++;
		tokensList.pop_back();
	}
	// cout << cpt << " Valuable tokens deleted" << endl;
}