/*
 * =====================================================================================
 *
 *       Filename:  the_function_Factory.cpp
 *
 *    Description:  File containing source code for creating functions using the function
 *                  factory class.
 *
 *        Version:  1.0
 *        Created:  18/02/16 10:38:12
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include "the_function_factory.hpp"
#include <iostream>
#include <sstream> 
#include <stdexcept>

/* 
 * ===  MEMBER FUNCTION CLASS : TheFunctionFactory  ======================================
 *         Name:  create
 *    Arguments:  std::string functionString - String containing function type.
 *      Returns:  A pointer to the created Function class.
 *  Description:  This function takes in a format and type string and uses this to create
 *                an instance of a class derived from the Function abstract base class.
 *                Syntax instructions can be found by running ./auto_diff -h. The else
 *                if block simply decides what class to create with what parameters based
 *                on the keyword string given. Recursively calls itself for functions
 *                within functions.
 * =====================================================================================
 */

namespace arb {

	Function * TheFunctionFactory::create(std::string functionString) {
		Function * newFunc = NULL ;
		std::stringstream functionStream(functionString) ;
		std::string functionType ;
		std::string nextArg ;
		functionStream >> functionType ;
		if (functionType.compare("X")==0) {
			newFunc = new XFunc() ;
			return newFunc ;
		} else if (functionType.compare("Sin")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Sin(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Cos")==0){	
			getline(functionStream, nextArg) ;
			newFunc = new Cos(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Tan")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Tan(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Cot")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Cot(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Sinh")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Sinh(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Cosh")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Cosh(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Tanh")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Tanh(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Coth")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Coth(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Exp")==0){
			getline(functionStream, nextArg) ;
			newFunc = new Exp(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("LogN")==0){
			getline(functionStream, nextArg) ;
			newFunc = new LogN(create(nextArg)) ;
			return newFunc ;
		} else if (functionType.compare("Power")==0){
			double exponent ;
			functionStream >> exponent ;
			getline(functionStream, nextArg) ;
			newFunc = new Power(create(nextArg), exponent) ;
			return newFunc ;
		} else if (functionType.find("Polynomial")==0){
			int order = 0 ;
			functionStream >> order ;
			std::vector<double> coefficients(order+1) ;
			for (int i = 0 ; i <= order ; ++i) {
				functionStream >> coefficients[i] ;
			}
			getline(functionStream, nextArg) ;
			newFunc = new Polynomial(coefficients, create(nextArg)) ;
			return newFunc ;
		} else if (functionType.find("LinearSum")==0){
			// Needs to extact two new function strings. //
			std::string leftArg ;
			std::string rightArg ;
			std::string component ;
			bool foundEndOfArg = false ;
			int expectedPlusses = 0 ;

			while (!foundEndOfArg) {
				functionStream >> component ;
				if (component.compare("LinearSum") == 0) {
					++expectedPlusses ;
				}
				if (component.compare("+") == 0) {
					if (expectedPlusses == 0) {
						foundEndOfArg = true ;
						break ;
					} else {
						--expectedPlusses ;
					}
				}
				leftArg.append(component) ;
				leftArg.append(" ") ;
			}
			foundEndOfArg = false ;
			int expectedEnds = 0 ;
			while (!foundEndOfArg) {
				functionStream >> component ;
				if (component.compare("LinearSum") == 0) {
					++expectedEnds ;
				}
				if (component.compare("EndSum") == 0) {
					if (expectedEnds == 0) {
						foundEndOfArg = true ;
						break ;
					} else {
						--expectedEnds ;
					}
				}
				rightArg.append(component) ;
				rightArg.append(" ") ;
			}
			newFunc = new LinearSum(create(leftArg), create(rightArg)) ;
			return newFunc ;
		} else if (functionType.find("Quotient")==0){	
			// Needs to extact two new function strings. //
			std::string leftArg ;
			std::string rightArg ;
			std::string component ;
			bool foundEndOfArg = false ;
			int expectedDivides = 0 ;

			while (!foundEndOfArg) {
				functionStream >> component ;
				if (component.compare("Quotient") == 0) {
					++expectedDivides ;
				}
				if (component.compare("/") == 0) {
					if (expectedDivides == 0) {
						foundEndOfArg = true ;
						break ;
					} else {
						--expectedDivides ;
					}
				}
				leftArg.append(component) ;
				leftArg.append(" ") ;
			}
			foundEndOfArg = false ;
			int expectedEnds = 0 ;
			while (!foundEndOfArg) {
				functionStream >> component ;
				if (component.compare("Quotient") == 0) {
					++expectedEnds ;
				}
				if (component.compare("EndQuotient") == 0) {
					if (expectedEnds == 0) {
						foundEndOfArg = true ;
						break ;
					} else {
						--expectedEnds ;
					}
				}
				rightArg.append(component) ;
				rightArg.append(" ") ;
			}
			newFunc = new Quotient(create(leftArg), create(rightArg)) ;
			return newFunc ;
		} else if (functionType.find("Product")==0){	
			// Needs to extact two new function strings. //
			std::string leftArg ;
			std::string rightArg ;
			std::string component ;
			bool foundEndOfArg = false ;
			int expectedMults = 0 ;

			while (!foundEndOfArg) {
				functionStream >> component ;
				if (component.compare("Product") == 0) {
					++expectedMults ;
				}
				if (component.compare("*") == 0) {
					if (expectedMults == 0) {
						foundEndOfArg = true ;
						break ;
					} else {

						--expectedMults ;
					}
				}
				leftArg.append(component) ;
				leftArg.append(" ") ;
			}
			foundEndOfArg = false ;
			int expectedEnds = 0 ;
			while (!foundEndOfArg) {
				functionStream >> component ;
				if (component.compare("Product") == 0) {
					++expectedEnds ;
				}
				if (component.compare("EndProduct") == 0) {
					if (expectedEnds == 0) {
						foundEndOfArg = true ;
						break ;
					} else {
						--expectedEnds ;
					}
				}
				rightArg.append(component) ;
				rightArg.append(" ") ;
			}
			newFunc = new Product(create(leftArg), create(rightArg)) ;
			return newFunc ;
		} else {
			throw std::invalid_argument("Unknown Syntax") ;
		}
	}		/* -----  end of member function create  ----- */

}
