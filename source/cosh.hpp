#ifndef COSH_HPP_0HMVSL8D
#define COSH_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  cosh.hpp
 *
 *    Description:  Header file containing declaration of cosh function class.
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
 *         Name:  Cosh
 *  Description:  Class describing cosh function.
 * =====================================================================================
 */

namespace arb {

	class Cosh : public Function {
	 public:
		Cosh(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Cosh() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Cosh  ----- */

}

#endif /* end of include guard: COSH_HPP_0HMVSL8D */
