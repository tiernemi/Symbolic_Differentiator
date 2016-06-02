#ifndef COS_HPP_0HMVSL8D
#define COS_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  cos.hpp
 *
 *    Description:  Header file containing declaration of cos function class.
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
 *         Name:  Cos
 *  Description:  Class describing cos function.
 * =====================================================================================
 */

namespace arb {

	class Cos : public Function {
	 public:
		Cos(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Cos() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Cos  ----- */

}

#endif /* end of include guard: COS_HPP_0HMVSL8D */
