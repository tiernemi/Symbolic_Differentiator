#ifndef SIN_HPP_0HMVSL8D
#define SIN_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  sin.hpp
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
 *         Name:  Sin
 *  Description:  Class describing sin function.
 * =====================================================================================
 */

namespace arb {

	class Sin : public Function {
	 public:
		Sin(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Sin() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Sin  ----- */

}

#endif /* end of include guard: SIN_HPP_0HMVSL8D */
