#ifndef FUNCTION_HPP_8THM3ZJA
#define FUNCTION_HPP_8THM3ZJA

/*
 * =====================================================================================
 *
 *       Filename:  function.hpp
 *
 *    Description:  Header file containing function abstract base class.
 *
 *        Version:  1.0
 *        Created:  18/02/16 10:27:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

/* 
 * ===  CLASS  =========================================================================
 *         Name:  Function
 *  Description:  Abstract base class for functions. Has evaluation of function and 
 *                evaluation of derivative functionality.
 * =====================================================================================
 */

namespace arb {

	class Function {
	 public:
		 virtual double operator()(const double & arg) const = 0 ;
		 virtual double deriv(const double & arg) const = 0 ;
		 virtual ~Function() {} ;
	} ;		/* -----  end of class Function  ----- */

}

#endif /* end of include guard: FUNCTION_HPP_8THM3ZJA */
