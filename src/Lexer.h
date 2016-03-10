#ifndef LEXER_H
#define LEXER_H

#include <iostream>
using namespace std;
#include <string>

// include Boost lib
#include <boost/regex.hpp>

#include "Symbol.h"


class Lexer
{
    public:
        Lexer(vector<string> fileLines);
        Symbol* getNext();
        bool consumeNext();
        bool has_next();

    private:
    	vector<string> fileLines;

};

#endif // LEXER_H