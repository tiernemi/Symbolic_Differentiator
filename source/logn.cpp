
/*
 * =====================================================================================
 *
 *       Filename:  logn.cpp
 *
 *    Description:  File containing source code for natural logarithm function class.
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

#include "logn.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : LogN  ===================================================
 *         Name:  LogN
 *    Arguments:  Function * fptr - Pointer to function in natural logarithm of form ln{f(x)}.
 *  Description:  Constructer for natural logarithm function.
 * =====================================================================================
 */

LogN::LogN(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function LogN  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : LogN  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the natural logarithm at x = arg.
 * =====================================================================================
 */

double LogN::operator()(const double & arg) const {
	return std::log((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : LogN  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of natural logarithm at x = arg.
 * =====================================================================================
 */

double LogN::deriv(const double & arg) const {
	return (*fptr).deriv(arg) / (*fptr)(arg) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : LogN  ======================================
 *         Name:  ~LogN
 *  Description:  Destructor for class.
 * =====================================================================================
 */

LogN::~LogN() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
