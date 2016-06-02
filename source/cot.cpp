/*
 * =====================================================================================
 *
 *       Filename:  cot.cpp
 *
 *    Description:  File containing source code for cot function class.
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

#include "cot.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Cot  ===================================================
 *         Name:  Cot
 *    Arguments:  Function * fptr - Pointer to function in cot of form tan(f(x)).
 *  Description:  Constructer for cot function.
 * =====================================================================================
 */

Cot::Cot(Function * fptr) : fptr{fptr} {
	;
}		/* -----  end of member function Cot  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cot  ====================================================
 *         Name:  operator
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the cot at x = arg.
 * =====================================================================================
 */

double Cot::operator()(const double & arg) const {
	return 1.f/(std::tan((*fptr)(arg))) ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cot  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of cot at x = arg.
 * =====================================================================================
 */

double Cot::deriv(const double & arg) const {
	return -(*fptr).deriv(arg) / std::pow(std::sin((*fptr)(arg)),2) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Cot  ======================================
 *         Name:  ~Cot
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Cot::~Cot() {
	delete fptr ;
}		/* -----  end of member function   ----- */

}
