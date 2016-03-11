
//
//  LutinLangInterperter
//  Lexer.h
//
//  Created by H4115 on 08/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
using namespace std;
#include <string>
#include "Tokens.h"

#include <boost/regex.hpp>

// #include "Symbol.h"


class Lexer
{
    public:
        Lexer(string filePath);
        void leftTrim(string &inputString);
        Tokens getNext();
        bool consumeNext();
        bool analyseNext(string inputToAnalyse, Tokens &tokenFetched, string &foundKeyword);
        bool analyseAll(vector<Tokens> &tokensList/*, vector<Symbol> symbolsList*/);
        Tokens getCurrentToken();

    private:
    	string fileLines;
    	Tokens lastTokenFetched;
    	vector<string> tokenList;
    	// TODO: replace with struct cursor
    	int line;
    	int column;
};

#endif // LEXER_H