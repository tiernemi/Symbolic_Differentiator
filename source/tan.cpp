/*
 * =====================================================================================
 *
 *       Filename:  tan.cpp
 *
 *    Description:  File containing source code for tan function class.
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

#include "tan.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Tan  ===================================================
 *         Name:  Tan
 *    Arguments:  Function * fptr - Pointer to function in tan of form tan(f(x)).
 *  Description:  Constructer for tan function.
 * =====================================================================================
 */

Tan::Tan(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Tan  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Tan  ====================================================
 *         Name:  operator
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the tan at x = arg.
 * =====================================================================================
 */

double Tan::operator()(const double & arg) const {
	return std::tan((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Tan  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of tan at x = arg.
 * =====================================================================================
 */

double Tan::deriv(const double & arg) const {
	return (*fptr).deriv(arg) / (std::cos((*fptr)(arg))*std::cos((*fptr)(arg))) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Tan  ======================================
 *         Name:  ~Tan
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Tan::~Tan() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
