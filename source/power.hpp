#ifndef POWER_HPP_0HMVSL8D
#define POWER_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  power.hpp
 *
 *    Description:  Header file containing declaration of power function class.
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
 *         Name:  Power
 *       Fields:  double exponent - The exponent of the function f(x)^n
 *  Description:  Class describing power function f(x)^n.
 * =====================================================================================
 */

namespace arb {

	class Power : public Function {
	 public:
		Power(Function * fptr, double exponent) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Power() ;
	 private:
		const Function * const fptr ;
		double exponent ;
	} ;		/* -----  end of class Power  ----- */

}

#endif /* end of include guard: POWER_HPP_0HMVSL8D */
