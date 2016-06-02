/*
 * =====================================================================================
 *
 *       Filename:  polynomial.cpp
 *
 *    Description:  File containing source code for functions in polynomial class.
 *
 *        Version:  1.0
 *        Created:  18/02/16 11:00:17
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include "polynomial.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Polynomial  ===========================================
 *         Name: Polynomial 
 *    Arguments: std::vector<double> coefficients - Vector of cofficients of polynomial
 *               expansion.
 *               Function * fptr - Function to evaluate in polynomial itself.
 *  Description: Polynomial constructor. Makes polynomial of the form \sum^N_0 a_n*f(x)^n
 * =====================================================================================
 */

Polynomial::Polynomial(std::vector<double> coefficients, Function * fptr) : fptr{fptr} {
	this->coefficients = coefficients ;
}		/* -----  end of member function   ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Polynomial  ==========================================
 *         Name:  operator
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the polynomial at x = arg.
 * =====================================================================================
 */
double Polynomial::operator()(const double & arg) const {
	double answer = 0.f ;
	for (unsigned int i = 0 ; i < coefficients.size() ; ++i) {
		answer += coefficients[i] * std::pow((*fptr)(arg),i) ;
	}
	return answer ;
}		/* -----  end of member function operator  ----- */


/* 
 * ===  MEMBER FUNCTION CLASS : Polynomial  ======================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of polynomial at x = arg.
 * =====================================================================================
 */

double Polynomial::deriv(const double & arg) const {
	double answer = 0.f ;
	for (unsigned int i = 1 ; i < coefficients.size() ; ++i) {
		answer += coefficients[i]* i * (*fptr).deriv(arg) * std::pow((*fptr)(arg),i-1) ;
	}
	return answer ;	
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Polynomial  ======================================
 *         Name:  ~Polynomial
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Polynomial::~Polynomial() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
