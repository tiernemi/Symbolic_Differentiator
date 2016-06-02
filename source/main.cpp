/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  The main function for testing function evaluations and their derivatives.
 *
 *        Version:  1.0
 *        Created:  18/02/16 20:53:24
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include "the_function_factory.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "getopt.h"
#include "test_funcs.hpp"
#include <chrono>
#include <ctime>
#include "instructions.hpp"
#include <stdexcept>

int main(int argc, char *argv[]) {

	std::string filename ;
	bool filenameGiven = false ;
	bool testFlag = false ;
	int choice ;
	while (1)	{	
		choice = getopt(argc, argv, "f:th");
	
		if (choice == -1)
			break;	
		switch( choice ) {
			case 'f':
				filenameGiven = true ;
				filename = optarg ;
				break;
			case 't':
				testFlag = true ;
				break ;
			case 'h':
				printInstructions() ;
				return EXIT_SUCCESS ;
			default:
				return EXIT_FAILURE;
		}
	}

	std::string functionString ; // Buffer string for file input. //
	std::vector<arb::Function *> functions ; // Vector of functions. //

	// If filename is given read from file,else read from stdin. //
	if (filenameGiven == true) {
		// Input and create functions based off definitions in the file. //
		std::ifstream equationInput(filename.c_str()) ;
		int lineNum = 0 ;
		while (std::getline(equationInput, functionString)) {
			try {
				arb::Function * newFunc = arb::TheFunctionFactory::create(functionString) ;
				functions.push_back(newFunc) ;
			} catch (std::invalid_argument) {
				std::cerr << "Unknown Syntax Encountered When Creating A Function" << std::endl ;
				std::cerr << "Skipping Expression " << lineNum << std::endl ;
			}
			++lineNum ;
		}
	} else {
		std::cout << "Input Functions, Type FIN to stop input : Run with -h to get syntax." << std::endl;
		while (std::getline(std::cin , functionString)) {
			if (functionString.compare("FIN") == 0) {
				break ;
			}
			try {
				arb::Function * newFunc = arb::TheFunctionFactory::create(functionString) ;
				functions.push_back(newFunc) ;
			} catch (std::invalid_argument) {
				std::cerr << "Unknown Syntax Encountered When Creating A Function" << std::endl ;
				std::cerr << "Skipping Expression " << std::endl ;
			}
		}
	}

	double arg ;
	std::cout << "Input argument x for functions f(x) defined in file " << filename << std::endl;
	std::cin >> arg ;

	// Testing mode. //
	if (testFlag) {
		// Set up arrays of hard-coded test functions. //
		testFunctions.push_back(&test_funcs1) ;
		testFunctions.push_back(&test_funcs2) ;
		testFunctions.push_back(&test_funcs3) ;
		testFunctions.push_back(&test_funcs4) ;
		testFunctions.push_back(&test_funcs5) ;
		testFunctions.push_back(&test_funcs6) ;
		testFunctionsDerivs.push_back(&test_deriv1) ;
		testFunctionsDerivs.push_back(&test_deriv2) ;
		testFunctionsDerivs.push_back(&test_deriv3) ;
		testFunctionsDerivs.push_back(&test_deriv4) ;
		testFunctionsDerivs.push_back(&test_deriv5) ;
		testFunctionsDerivs.push_back(&test_deriv6) ;

		double eval ;
		std::chrono::time_point<std::chrono::system_clock> start, end;
		std::chrono::duration<double> duration ;
		for (unsigned int i = 0 ; i < functions.size() ; ++i) {
			std::cout << "FUNCTION " << i+1 << std::endl ;

			start = std::chrono::system_clock::now();
			eval = (*functions[i])(arg) ;
			end = std::chrono::system_clock::now();
 			duration = end-start ;
			std::cout << "F(" << arg << ") AUTODIFF EVAL : " << eval << std::endl ;
			std::cout << " : Time : " << duration.count() << std::endl ;

			start = std::chrono::system_clock::now();
			eval = testFunctions[i](arg)  ;
			end = std::chrono::system_clock::now();
 			duration = end-start ;
			std::cout << "F(" << arg << ") TEST EVAL : " << eval << std::endl ;
			std::cout << " : Time : " << duration.count() << std::endl ;

			start = std::chrono::system_clock::now();
			eval = (*functions[i]).deriv(arg) ;
			end = std::chrono::system_clock::now();
 			duration = end-start ;
			std::cout << "F'(" << arg << ") AUTODIFF EVAL : " << eval << std::endl ;
			std::cout << " : Time : " << duration.count() << std::endl ;

			start = std::chrono::system_clock::now();
			eval = testFunctionsDerivs[i](arg) ;
			end = std::chrono::system_clock::now();
 			duration = end-start ;
			std::cout << "F'(" << arg << ") TEST EVAL : " << eval << std::endl ;
			std::cout << " : Time : " << duration.count() << std::endl ;
		}
	} else {
		for (unsigned int i = 0 ; i < functions.size() ; ++i) {
			std::cout << "FUNCTION " << i+1 << std::endl ;
			std::cout << "F(" << arg << ") AUTODIFF EVAL : " << (*functions[i])(arg) << std::endl ;
			std::cout << "F'(" << arg << ") AUTODIFF EVAL : " << (*functions[i]).deriv(arg) << std::endl ;	
		}
	}

	for (unsigned int i = 0 ; i < functions.size() ; ++i) {
		delete functions[i] ;
	}
	return 0;
}
