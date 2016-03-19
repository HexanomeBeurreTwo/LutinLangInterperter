//
//  LutinLangInterperter
//  ArgParser.cpp
//
//  Created by H4115 on 19/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "ArgParser.h"
using namespace std;
using namespace po = boost::program_options; 

ArgParser::ArgParser(int argc, char* argv){
	displayFlag = false;
    executionFlag = false;
    staticAnalysisFlag = false;
    transformationFlag = false;
    filePath = "";

	//DiscoverFlags

}

ArgParser::~ArgParser()	{

}
