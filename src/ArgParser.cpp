//
//  LutinLangInterperter
//  ArgParser.cpp
//
//  Created by H4115 on 19/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "ArgParser.h"
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
using namespace std;
using namespace boost::filesystem;

namespace 
{ 
  const size_t ERROR_IN_COMMAND_LINE = 1; 
  const size_t SUCCESS = 0; 
  const size_t ERROR_UNHANDLED_EXCEPTION = 2; 
 
} // namespace

ArgParser::ArgParser(int argc, char const *argv[]){
	printFlag = false;
    executionFlag = false;
    staticAnalysisFlag = false;
    optimizeFlag = false;
    error = true;
    filePath = "";

	//DiscoverFlags
    if(discoverFlags(argc, argv) == SUCCESS)	{
    	//Lets continue
    	error = false;
    }
}

int ArgParser::discoverFlags(const int argc, char const *argv[])	{
	try 
  	{ 
	/** Define and parse the program options 
	 */ 

  	string sourceFile;
	namespace po = boost::program_options;
	po::options_description desc("Allowed options"); 
	desc.add_options() 
	  ("help,h", "Print help messages")
	  ("print,p", "Print code")
	  ("execute,e", "Execute program")
	  ("optimize,o", "Optimize / Transform program")
	  ("analyse,a", "Diagnostic static errors")
	  ("input,i", po::value<std::string>()->required(), "programme lutin, argument par défaut");

    po::positional_options_description p;
    p.add("input", -1);

	po::variables_map vm; 
	try 
	{ 
		po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
		po::notify(vm);

		/** --help option 
		*/ 
		if ( vm.count("help")  ) { 
			std::cout << "Basic Command Line Parameter App" << std::endl 
			          << desc << std::endl; 
			return SUCCESS; 
		}

		if (argc == 1) { 
			std::cout << "Basic Command Line Parameter App" << std::endl 
			          << desc << std::endl; 
			return ERROR_IN_COMMAND_LINE; 
		}

        if (vm.count("e")) executionFlag = true;
        if (vm.count("a")) staticAnalysisFlag = true;
        if (vm.count("o")) optimizeFlag = true;
        if (vm.count("p")) printFlag = true;

		if (vm.count("input")) {
			sourceFile = vm["input"].as<std::string>();
			path p(sourceFile);
			if (exists(p))	{
				if (is_regular_file(p))
				{
					if (p.has_extension() && p.extension() == ".lt")	{
						filePath = sourceFile;
						return SUCCESS;
					}	else	{
						cout << "Filename has no extension or wrong one (" << p.extension() << "). Should have .lut extension" << endl;
					}
				}	else	{
					cout << "Input argument is not a regular file" << endl;
				}
			}	else	{
				cout << "Input path does not exist" << endl;
			}
			return ERROR_IN_COMMAND_LINE;
		}

		po::notify(vm); // throws on error, so do after help in case 
		              // there are any problems 
	} 
	catch(po::error& e) 
	{ 
	  std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
	  std::cerr << desc << std::endl; 
	  return ERROR_IN_COMMAND_LINE; 
	} 

	// application code here // 

	} 
	catch(std::exception& e) 
	{ 
	std::cerr << "Unhandled Exception reached the top of main: " 
	          << e.what() << ", application will now exit" << std::endl; 
	return ERROR_UNHANDLED_EXCEPTION; 

	}

	return ERROR_UNHANDLED_EXCEPTION;
}

bool ArgParser::getPrintFlag()	{
	return printFlag;
}

bool ArgParser::getExecutionFlag()	{
	return executionFlag;
}

bool ArgParser::getStaticAnalysisFlag()	{
	return staticAnalysisFlag;
}

bool ArgParser::getOptimizeFlag()	{
	return optimizeFlag;
}

bool ArgParser::getError()	{
	return error;
}

string ArgParser::getFilePath()	{
	return filePath;
}

ArgParser::~ArgParser()	{

}
