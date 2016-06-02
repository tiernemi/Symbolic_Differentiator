/*
 * =====================================================================================
 *
 *       Filename:  exp.cpp
 *
 *    Description:  File containing source code for exponential function class.
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

#include "exp.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Exp  ===================================================
 *         Name:  Exp
 *    Arguments:  Function * fptr - Pointer to function in exponential of form e^{f(x)}.
 *  Description:  Constructer for exponential function.
 * =====================================================================================
 */

Exp::Exp(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Exp  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Exp  ====================================================
 *         Name:  ::operatoperatexp
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the exponential at x = arg.
 * =====================================================================================
 */

double Exp::operator()(const double & arg) const {
	return std::exp((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Exp  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of exponential at x = arg.
 * =====================================================================================
 */

double Exp::deriv(const double & arg) const {
	return (*fptr).deriv(arg) * exp((*fptr)(arg)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Exp  ======================================
 *         Name:  ~Exp
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Exp::~Exp() {
	delete fptr ;
}		/* -----  end of member function   ----- */


}
