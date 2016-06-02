#ifndef COTH_HPP_0HMVSL8D
#define COTH_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  coth.hpp
 *
 *    Description:  Header file containing declaration of sin function class.
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
 *         Name:  Coth
 *  Description:  Class describing coth function.
 * =====================================================================================
 */

namespace arb {

	class Coth : public Function {
	 public:
		Coth(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Coth() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Coth  ----- */

}

#endif /* end of include guard: COTH_HPP_0HMVSL8D */
