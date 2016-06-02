/*
 * =====================================================================================
 *
 *       Filename:  tanh.cpp
 *
 *    Description:  File containing source code for tanh function class.
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

#include "tanh.hpp"
#include "exp.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Tanh  ===================================================
 *         Name:  Tanh
 *    Arguments:  Function * fptr - Pointer to function in tanh of form sinh(x)
 *  Description:  Constructer for tanh function.
 * =====================================================================================
 */

Tanh::Tanh(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Tanh  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Tanh  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the tanh at x = arg.
 * =====================================================================================
 */

double Tanh::operator()(const double & arg) const {
	return std::tanh((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Tanh  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of tanh at x = arg.
 * =====================================================================================
 */

double Tanh::deriv(const double & arg) const {
	double eval = std::cosh((*fptr)(arg)) ;
	return (*fptr).deriv(arg) * (1.f/(eval*eval)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Tanh  ======================================
 *         Name:  ~Tanh
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Tanh::~Tanh() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
