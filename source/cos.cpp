/*
 * =====================================================================================
 *
 *       Filename:  cos.cpp
 *
 *    Description:  File containing source code for cos function class.
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

#include "cos.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Cos  ===================================================
 *         Name:  Cos
 *    Arguments:  Function * fptr - Pointer to function in cos of form cos(f(x))
 *  Description:  Constructer for cos function.
 * =====================================================================================
 */

Cos::Cos(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Cos  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cos  ====================================================
 *         Name:  operatoper()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the cos at x = arg.
 * =====================================================================================
 */

double Cos::operator()(const double & arg) const {
	return std::cos((*fptr)(arg)) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cos  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of cos at x = arg.
 * =====================================================================================
 */

double Cos::deriv(const double & arg) const {
	return (*fptr).deriv(arg) * -std::sin((*fptr)(arg)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cos  ======================================
 *         Name:  ~Cos
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Cos::~Cos() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
