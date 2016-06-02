/*
 * =====================================================================================
 *
 *       Filename:  sinh.cpp
 *
 *    Description:  File containing source code for sinh function class.
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

#include "sinh.hpp"
#include "exp.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Sinh  ===================================================
 *         Name:  Sinh
 *    Arguments:  Function * fptr - Pointer to function in sinh of form sinh(x)
 *  Description:  Constructer for sinh function.
 * =====================================================================================
 */

Sinh::Sinh(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Sinh  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Sinh  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the sinh at x = arg.
 * =====================================================================================
 */

double Sinh::operator()(const double & arg) const {
	return std::sinh((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Sinh  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of sinh at x = arg.
 * =====================================================================================
 */

double Sinh::deriv(const double & arg) const {
	return (*fptr).deriv(arg)*std::cosh((*fptr)(arg)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Sinh  ======================================
 *         Name:  ~Sinh
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Sinh::~Sinh() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
