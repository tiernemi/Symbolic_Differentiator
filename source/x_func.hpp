
#ifndef XFUNC_HPP_0HMVSL8D
#define XFUNC_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  x_func.hpp
 *
 *    Description:  Header file containing declaration of xFunc function class.
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
 *         Name:  XFunc
 *  Description:  Class describing xFunc which is the basic function x
 * =====================================================================================
 */

namespace arb {

	class XFunc : public Function {
	 public:
		XFunc() ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~XFunc() ;
	} ;		/* -----  end of class XFunc  ----- */

}

#endif /* end of include guard: XFUNC_HPP_0HMVSL8D */
