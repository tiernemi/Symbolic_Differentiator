
#ifndef QUOTIENT_HPP_0HMVSL8D
#define QUOTIENT_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  quotient.hpp
 *
 *    Description:  Header file containing declaration of quotient function class.
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
 *         Name:  Quotient
 *       Fields:  Function * fptr1 - Function pointer to first function in f(x)/g(x).
 *                Function * fptr2 - Function pointer to second function in f(x)/g(x).
 *  Description:  Class describing quotient of two functions and its derivative. 
 * =====================================================================================
 */

namespace arb {

	class Quotient : public Function {
	 public:
		Quotient(Function * fptr1, Function * fptr2) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Quotient() ;
	 private:
		const Function * const fptr1 ;
		const Function * const fptr2 ;
	} ;		/* -----  end of class Quotient  ----- */

}

#endif /* end of include guard: QUOTIENT_HPP_0HMVSL8D */
