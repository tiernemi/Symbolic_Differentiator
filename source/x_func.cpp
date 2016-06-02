/*
 * =====================================================================================
 *
 *       Filename:  x_func.cpp
 *
 *    Description:  File containing source code for xFunc function class.
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

#include "x_func.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : XFunc  ===================================================
 *         Name:  XFunc
 *  Description:  Constructer for xFunc function.
 * =====================================================================================
 */

XFunc::XFunc() {
	;
}		/* -----  end of member function XFunc  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : XFunc  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the xFunc at x = arg.
 * =====================================================================================
 */

double XFunc::operator()(const double & arg) const {
	return arg ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : XFunc  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of xFunc at x = arg.
 * =====================================================================================
 */

double XFunc::deriv(const double & arg) const {
	return 1 ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : XFunc  ======================================
 *         Name:  ~XFunc
 *  Description:  Destructor for class.
 * =====================================================================================
 */

XFunc::~XFunc() {
	;
}		/* -----  end of member function   ----- */

}
