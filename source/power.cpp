/*
 * =====================================================================================
 *
 *       Filename:  power.cpp
 *
 *    Description:  File containing source code for power function class.
 *
 *        Version:  1.0
 *        Created:  18/02/16 11:43:48
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include "power.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Power  ===================================================
 *         Name:  Power
 *    Arguments:  Function * fptr - Pointer to function in f(x) of in f(x)^n
 *                double exponent - Exponent n in function f(x)^n.
 *  Description:  Constructer for power function.
 * =====================================================================================
 */

Power::Power(Function * fptr, double exponent) : fptr{fptr} {
	this->exponent = exponent ;
}		/* -----  end of member function Power  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Power  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the power at x = arg.
 * =====================================================================================
 */

double Power::operator()(const double & arg) const {
	return std::pow((*fptr)(arg), exponent) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Power  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of power at x = arg.
 * =====================================================================================
 */

double Power::deriv(const double & arg) const {
	return (*fptr).deriv(arg)*(exponent)*std::pow((*fptr)(arg), exponent-1.f) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Power  ======================================
 *         Name:  ~Power
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Power::~Power() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
