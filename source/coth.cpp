/*
 * =====================================================================================
 *
 *       Filename:  coth.cpp
 *
 *    Description:  File containing source code for coth function class.
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

#include "coth.hpp"
#include "exp.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Coth  ===================================================
 *         Name:  Coth
 *    Arguments:  Function * fptr - Pointer to function in coth of form cothh(x)
 *  Description:  Constructer for coth function.
 * =====================================================================================
 */

Coth::Coth(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Coth  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Coth  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the coth at x = arg.
 * =====================================================================================
 */

double Coth::operator()(const double & arg) const {
	return 1.f/(std::tanh((*fptr)(arg))) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Coth  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of coth at x = arg.
 * =====================================================================================
 */

double Coth::deriv(const double & arg) const {
	double eval = std::sinh((*fptr)(arg)) ;
	return -(*fptr).deriv(arg) * (1.f/(eval*eval)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Coth  ======================================
 *         Name:  ~Coth
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Coth::~Coth() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
