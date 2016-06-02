/*
 * =====================================================================================
 *
 *       Filename:  sin.cpp
 *
 *    Description:  File containing source code for sin function class.
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

#include "sin.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Sin  ===================================================
 *         Name:  Sin
 *    Arguments:  Function * fptr - Pointer to function in h of form sinh(x)
 *  Description:  Constructer for sin function.
 * =====================================================================================
 */

Sin::Sin(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Sin  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Sin  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the sin at x = arg.
 * =====================================================================================
 */

double Sin::operator()(const double & arg) const {
	return std::sin((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Sin  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of sin at x = arg.
 * =====================================================================================
 */

double Sin::deriv(const double & arg) const {
	return (*fptr).deriv(arg) * std::cos((*fptr)(arg)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Sin  ======================================
 *         Name:  ~Sin
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Sin::~Sin() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
