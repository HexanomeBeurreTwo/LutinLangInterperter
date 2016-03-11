
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

Tokens Lexer::getNext()	{
	Tokens tokenFetched;
	string foundKeyword;
	analyseNext(fileLines, tokenFetched, foundKeyword);
	lastTokenFetched = tokenFetched;
	return lastTokenFetched;
}

bool Lexer::consumeNext()	{
	// if column end -> update line && column = 0
	// else column++
	return false;
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

bool Lexer::analyseAll(vector<Tokens> &tokensList/*, vector<Symbol> symbolsList*/)	{
	string inputToAnalyse = fileLines;
	cout << "Analysis begin..." << endl;
	do
	{
		leftTrim(inputToAnalyse);
		cout << "[" << inputToAnalyse << "] @" << line+1 << "," << column+1 << endl;

		Tokens tokenFetched;
		string foundKeyword;
		analyseNext(inputToAnalyse, tokenFetched, foundKeyword);
		tokensList.push_back(tokenFetched);
		// symbolsList.push_back(new Symbol(...))
		if (tokenFetched == INVALID)
		{
			//TODO: Add Error Message
			cout << "Analysis did not ended well..." << endl;
			return false;
		}
		// Remove word from input
		int numOfCharToRemove = foundKeyword.size();
		inputToAnalyse.erase(0, numOfCharToRemove);

		//Cursor update
		column += numOfCharToRemove;
	} while (inputToAnalyse.length() > 0);
	tokensList.push_back(END_OF_FILE);
	cout << "Analysis ended..." << endl;
	return true;
}

bool Lexer::analyseNext(string inputToAnalyse, Tokens &tokenFetched, string &foundKeyword)	{
	boost::match_results<string::const_iterator> results;
	if (regex_search(inputToAnalyse, results, keyword))	{
		// cout << "-- 1 --" << endl;
		// cout << "--" << results[0] << "--" << endl;
		// cout << "-------" << endl;
		foundKeyword = results[0].str();
		switch(foundKeyword[0])	{
			case 'c':
				cout << "It's a const!" << endl;
				tokenFetched = CONST;
				break;
			case 'v':
				cout << "It's a var!" << endl;
				tokenFetched = VAR;
				break;
			case 'e':
				cout << "It's a ecrire!" << endl;
				tokenFetched = WRITE;
				break;
			case 'l':
				cout << "It's a lire!" << endl;
				tokenFetched = READ;
				break;
			default:
				cout << "It's an error!" << endl;
				tokenFetched = INVALID;
				return false;
				break;
		}
	}
	else if (regex_search(inputToAnalyse, results, identifier))	{
		// cout << "-- 2 --" << endl;
		// cout << "--" << results[0] << "--" << endl;
		// cout << "-------" << endl;
		foundKeyword = results[0].str();
		cout << "It's an identifier : " << foundKeyword << "!" << endl;
		tokenFetched = ID;
	}
	else if (regex_search(inputToAnalyse, results, number))	{
		// cout << "-- 3 --" << endl;
		// cout << "--" << results[0] << "--" << endl;
		foundKeyword = results[0].str();
		cout << "It's a number : " << foundKeyword << "!" << endl;
		tokenFetched = VAL;
	}
	else if (regex_search(inputToAnalyse, results, operators))	{
		// cout << "-- 4 --" << endl;
		// cout << "--" << results[0] << "--" << endl;
		foundKeyword = results[0].str();
		switch(foundKeyword[0])	{
			case '+':
				cout << "It's a plus!" << endl;
				tokenFetched = PLUS;
				break;
			case '-':
				cout << "It's a minus!" << endl;
				tokenFetched = MINUS;
				break;
			case '*':
				cout << "It's a multiply!" << endl;
				tokenFetched = MULT;
				break;
			case '/':
				cout << "It's a divide!" << endl;
				tokenFetched = DIVIDE;
				break;
			case '(':
				cout << "It's a open parenthesis!" << endl;
				tokenFetched = OPENBY;
				break;
			case ')':
				cout << "It's a close parenthesis!" << endl;
				tokenFetched = CLOSEBY;
				break;
			case ';':
				cout << "It's an end line!" << endl;
				tokenFetched = END;
				break;
			case '=':
				cout << "It's an equal!" << endl;
				tokenFetched = EQUAL;
				break;
			case ',':
				cout << "It's a separator!" << endl;
				tokenFetched = SEP;
				break;
			case ':':
				cout << "It's an affectation!" << endl;
				tokenFetched = AFFECT;
				break;
			default:
				cout << "It's an error!" << endl;
				tokenFetched = INVALID;
				return false;
				break;      
		} 
	}
	else {
		cout << "It's an error!" << endl;
		foundKeyword = "";
		tokenFetched = INVALID;
		return false;
	}
	return true;
}

Tokens Lexer::getCurrentToken()	{
	return lastTokenFetched;
}

Lexer::Lexer(string inputString) : fileLines(inputString)	{
	//Read file & get code
	lastTokenFetched = INVALID;
	line = 0;
	column = 0;
}