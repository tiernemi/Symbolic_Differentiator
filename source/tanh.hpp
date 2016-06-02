#ifndef TANH_HPP_0HMVSL8D
#define TANH_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  tanh.hpp
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
 *         Name:  Tanh
 *  Description:  Class describing tanh function.
 * =====================================================================================
 */

namespace arb {

	class Tanh : public Function {
	 public:
		Tanh(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Tanh() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Tanh  ----- */

}

#endif /* end of include guard: TANH_HPP_0HMVSL8D */
