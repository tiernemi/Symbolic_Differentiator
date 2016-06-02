/*
 * =====================================================================================
 *
 *       Filename:  cosh.cpp
 *
 *    Description:  File containing source code for cosh function class.
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

#include "cosh.hpp"
#include "exp.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Cosh  ===================================================
 *         Name:  Cosh
 *    Arguments:  Function * fptr - Pointer to function in cosh of form sinh(x)
 *  Description:  Constructer for cosh function.
 * =====================================================================================
 */

Cosh::Cosh(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Cosh  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cosh  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the cosh at x = arg.
 * =====================================================================================
 */



double Cosh::operator()(const double & arg) const {
	return std::cosh((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cosh  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of cosh at x = arg.
 * =====================================================================================
 */

double Cosh::deriv(const double & arg) const {
	return (*fptr).deriv(arg)*std::sinh((*fptr)(arg)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cosh  ======================================
 *         Name:  ~Cosh
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Cosh::~Cosh() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
