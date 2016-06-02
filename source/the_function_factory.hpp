#ifndef THEFUNCTIONFACTORY_HPP_QLF78JHQ
#define THEFUNCTIONFACTORY_HPP_QLF78JHQ

/*
 * =====================================================================================
 *
 *       Filename:  the_function_factory.hpp
 *
 *    Description:  Header file containing function factory class declaration. This class
 *                  is used to create objects of type Function.
 *
 *        Version:  1.0
 *        Created:  18/02/16 10:35:02
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include <string>
#include "function.hpp"
#include "cos.hpp"
#include "sin.hpp"
#include "tan.hpp"
#include "cot.hpp"
#include "cosh.hpp"
#include "sinh.hpp"
#include "tanh.hpp"
#include "coth.hpp"
#include "exp.hpp"
#include "logn.hpp"
#include "power.hpp"
#include "linear_sum.hpp"
#include "polynomial.hpp"
#include "product.hpp"
#include "quotient.hpp"
#include "power.hpp"
#include "x_func.hpp"

/* 
 * ===  CLASS  =========================================================================
 *         Name:  TheFunctionFactory
 *  Description:  Function factory class used to create instances of Functions.
 * =====================================================================================
 */

namespace arb {

	class TheFunctionFactory {
	 public:
		 static Function * create(std::string functionString) ;
	} ;

}

#endif /* end of include guard: THEFUNCTIONFACTORY_HPP_QLF78JHQ */
