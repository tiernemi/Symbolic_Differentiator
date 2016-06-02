#ifndef POLYNOMIAL_HPP_QVXW0CLX
#define POLYNOMIAL_HPP_QVXW0CLX

/*
 * =====================================================================================
 *       Filename:  polynomial.hpp
 *
 *    Description:  This header file contains the declaration of the polynomial class.
 *                  This class is used to evaluate functions of the form 
 *                  \sum^N_0 a_n*f(x)^n
 *
 *        Version:  1.0
 *        Created:  18/02/16 10:53:55
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include <vector>
#include "function.hpp"

/* 
 * ===  CLASS  =========================================================================
 *         Name:  Polynomial
 *       Fields:  std::vector<double> coefficients - Vector of coefficients before each
 *                power of f(x) in the polynomial.
 *                const Function * const fptr - Pointer to function f(x) in polynomial.
 *  Description:  This class is used to evaluate a polynomial and its derivative for
 *                an arbitrary order of polynomial.
 * =====================================================================================
 */

namespace arb {

	class Polynomial : public Function {
	 public:
		Polynomial(std::vector<double> coefficients, Function * ftpr) ;
		double operator()(const double & arg) const ;
		double deriv(const double & arg) const ;
		virtual ~Polynomial() ;
	 private:
		std::vector<double> coefficients ;
		const Function * const fptr ;
	} ;		/* -----  end of class Polynomial  ----- */

}

#endif /* end of include guard: POLYNOMIAL_HPP_QVXW0CLX */
