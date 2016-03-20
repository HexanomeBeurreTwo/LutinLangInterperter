
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
        ~Lexer();
        Lexer(string filePath);
        void leftTrim(string &inputString);
        ValuableToken getNext();
        bool consumeNext();
        bool hasNext();
        bool analyseNext(string inputToAnalyse, ValuableToken *tokenFetched, string &foundKeyword);
        bool analyseAll();
        ValuableToken getCurrentToken();
        vector<ValuableToken*> tokensList;

    private:
        string fileLines;
        ValuableToken lastTokenFetched;
        unsigned int cursor;
        // TODO: replace with struct cursor
        int line;
        int column;
};

#endif // LEXER_H