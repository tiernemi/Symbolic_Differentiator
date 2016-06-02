#ifndef EXP_HPP_0HMVSL8D
#define EXP_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  exp.hpp
 *
 *    Description:  Header file containing declaration of exponential function class.
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
 *         Name:  Exp
 *  Description:  Class describing exponential function.
 * =====================================================================================
 */

namespace arb {

	class Exp : public Function {
	 public:
		Exp(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Exp() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Exp  ----- */

}

#endif /* end of include guard: EXP_HPP_0HMVSL8D */
