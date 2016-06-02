#ifndef COT_HPP_0HMVSL8D
#define COT_HPP_0HMVSL8D

/*
 * =====================================================================================
 *
 *       Filename:  cot.hpp
 *
 *    Description:  Header file containing declaration of cot function class.
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
 *         Name:  Cot
 *  Description:  Class describing cot function.
 * =====================================================================================
 */

namespace arb {

	class Cot : public Function {
	 public:
		Cot(Function * fptr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Cot() ;
	 private:
		const Function * const fptr ;
	} ;		/* -----  end of class Cot  ----- */

}

#endif /* end of include guard: COT_HPP_0HMVSL8D */
