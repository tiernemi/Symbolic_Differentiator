#ifndef SINH_HPP_0HMVSL8D
#define SINH_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  exp.hpp
 *
 *    Description:  Header file containing declaration of sinh function class.
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
 *         Name:  Sinh
 *  Description:  Class describing sinh function.
 * =====================================================================================
 */

namespace arb {

	class Sinh : public Function {
	 public:
		Sinh(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Sinh() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Sinh  ----- */

}

#endif /* end of include guard: SINH_HPP_0HMVSL8D */
