/*
 * =====================================================================================
 *
 *       Filename:  instructions.cpp
 *
 *    Description:  File containing source for printing verbose instructions.
 *
 *        Version:  1.0
 *        Created:  20/02/16 12:16:19
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include "instructions.hpp"
#include <iostream>

void printInstructions() {
	std::cout << ".................VERBOSE INSTRUCTIONS.............." << std::endl;
	std::cout << "USAGE : ./auto_diff -f [FILENAME] [OPTIONS]" << std::endl ;
	std::cout << "OPTIONS : -t - Test mode, compares functions to test functions and outputs times" << std::endl;
	std::cout << "OPTIONS : -h - Prints out instructions" << std::endl ;
	std::cout << ".................FILE FORMAT ......................" << std::endl;
	std::cout << "Basic file format given to -f : [FUNCTYPE] [FUNCPARAMS] [FUNCARG]" << std::endl;
	std::cout << "[FUNCARG] can be another function g(x) of the form [FUNCTYPE] [FUNCPARAMS] [FUNCARG]" << std::endl;
	std::cout << "SYNTAX :" << std::endl ;
	std::cout << "X - Basic function f(x) = x" << std::endl;
	std::cout << "Polynomial [ORDER] [COEFFICIENTS] [FUNCARG] - Polynomial of the form f(x) = \\sum_0^n a_n (g(x))^n" << std::endl;
	std::cout << "Sin [FUNCARG] - f(x) = Sin(g(x))" << std::endl;
	std::cout << "Cos [FUNCARG] - f(x) = Cos(g(x))" << std::endl;
	std::cout << "Tan [FUNCARG] - f(x) = Tan(g(x))" << std::endl;
	std::cout << "Cot [FUNCARG] - f(x) = Cot(g(x))" << std::endl;
	std::cout << "Sinh [FUNCARG] - f(x) = Sinh(g(x))" << std::endl;
	std::cout << "Cosh [FUNCARG] - f(x) = Cosh(g(x))" << std::endl;
	std::cout << "Tanh [FUNCARG] - f(x) = Tanh(g(x))" << std::endl;
	std::cout << "Coth [FUNCARG] - f(x) = Coth(g(x))" << std::endl;
	std::cout << "LogN [FUNCARG] - f(x) = ln(g(x))" << std::endl;
	std::cout << "Exp [FUNCARG] - f(x) = exp(g(x))" << std::endl;
	std::cout << "Power [EXPONENT] [FUNCARG] - f(x) = g(x)^n" << std::endl;
	std::cout << "Product [FUNCARG1] * [FUNCARG2] EndProduct - f(x) = g(x) * h(x) " << std::endl;
	std::cout << "Quotient [FUNCARG1] / [FUNCARG2] EndQuotient - f(x) = g(x) / h(x) " << std::endl;
	std::cout << "LinearSum [FUNCARG1] + [FUNCARG2] EndLinearSum - f(x) = g(x) + h(x) " << std::endl;
}
