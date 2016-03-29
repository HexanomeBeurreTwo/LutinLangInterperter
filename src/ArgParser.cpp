//
//  LutinLangInterperter
//  ArgParser.cpp
//
//  Created by H4115 on 19/03/2016.
//  Copyright (c) 2016 H4115. All rights reserved.
//

#include "Debug.h"
#include "ArgParser.h"
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <fstream>
using namespace std;
using namespace boost::filesystem;

namespace
{
  const size_t SUCCESS = 0;
  const size_t ERROR_IN_COMMAND_LINE = 1;
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

size_t ArgParser::discoverFlags(const int argc, char const *argv[])	{
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
	("input,i", po::value<std::string>()->required(), "Lutin program, default argument filename");

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
	    std::cout << "Lutin Interpreter App" << std::endl
		      << desc << std::endl;
	    return SUCCESS;
	  }

	  if (vm.count("execute")) executionFlag = true;
	  if (vm.count("analyse")) staticAnalysisFlag = true;
	  if (vm.count("optimize")) optimizeFlag = true;
	  if (vm.count("print")) printFlag = true;

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
		    cerr << "Filename has no extension or wrong one (" << p.extension() << "). Should have .lt extension" << endl;
		  }
		}	else	{
		cerr << "Input argument is not a regular file" << endl;
	      }
	    }	else	{
	      // cerr << "Input path does not exist" << endl;
	      cerr << "Erreur a l'ouverture du fichier " << sourceFile << endl;
	    }

	    return ERROR_IN_COMMAND_LINE;
	  }

	  po::notify(vm); // throws on error, so do after help in case
	  // there are any problems
	}
      catch(po::error& e)
	{
	  if (argc == 1) {
	    cerr << "Erreur, veuillez specifier des arguments\n  Utilisation :" << endl;
	    cerr << "\t../lut [-p] [-a] [-e] [-o] source.lt" << endl
		 << "\t\t[-p] affiche le code source reconnu" << endl
		 << "\t\t[-a] analyse le programme de maniere statique" << endl
		 << "\t\t[-e] execute interactivement le programme" << endl
		 << "\t\t[-o] optimise les expressions et instructions" << endl;
	    // << desc << std::endl;
	    return ERROR_IN_COMMAND_LINE;
	  }
	  else	{
	    std::cerr << "ERROR: " << e.what() << std::endl << std::endl;
	    std::cerr << desc << std::endl;
	    return ERROR_IN_COMMAND_LINE;
	  }
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
