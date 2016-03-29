
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


class ArgParser
{
    public:
        ~ArgParser();
        ArgParser(int argc, char const *argv[]);
        size_t discoverFlags(const int argc, char const *argv[]);
        bool getPrintFlag();
        bool getExecutionFlag();
        bool getStaticAnalysisFlag();
        bool getOptimizeFlag();
        bool getError();
        string getFilePath();

    private:
        bool printFlag;
        bool executionFlag;
        bool staticAnalysisFlag;
        bool optimizeFlag;
        bool error;
        string filePath;
};

#endif // ARG_PARSER_H
