#ifndef TAN_HPP_0HMVSL8D
#define TAN_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  tan.hpp
 *
 *    Description:  Header file containing declaration of tan function class.
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
 *         Name:  Tan
 *  Description:  Class describing tan function.
 * =====================================================================================
 */

namespace arb {

	class Tan : public Function {
	 public:
		Tan(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Tan() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Tan  ----- */

}

#endif /* end of include guard: TAN_HPP_0HMVSL8D */
