
//
//  LutinLangInterperter
//  ArgParser.h
//
//  Created by H4115 on 19/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <iostream>
using namespace std;
#include <string>

#include <boost/program_options.hpp>

// #include "Symbol.h"


class ArgParser
{
    public:
        ~ArgParser();
        ArgParser(string filePath);

    private:
        bool displayFlag;
        bool executionFlag;
        bool staticAnalysisFlag;
        bool transformationFlag;
};

#endif // ARG_PARSER_H