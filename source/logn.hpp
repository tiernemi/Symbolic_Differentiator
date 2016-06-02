
#ifndef LOGN_HPP_0HMVSL8D
#define LOGN_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  exp.hpp
 *
 *    Description:  Header file containing declaration of natural logarithm function class.
 *
 *        Version:  1.0
 *        Created:  18/02/16 11:39:01
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include "function.hpp"

/* 
 * ===  CLASS  =========================================================================
 *         Name:  LogN
 *       Fields:  const Function * const fptr - Pointer to function in log of form log_n{f(x)}
 *  Description:  Class describing natural logarithm function.
 * =====================================================================================
 */

namespace arb {

	class LogN : public Function {
	 public:
		LogN(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~LogN() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class LogN  ----- */

}

#endif /* end of include guard: LOGN_HPP_0HMVSL8D */
