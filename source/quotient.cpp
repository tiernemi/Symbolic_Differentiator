/*
 * =====================================================================================
 *
 *       Filename:  quotient.cpp
 *
 *    Description:  File containing source code for quotient function class.
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

#include "quotient.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Quotient  ===================================================
 *         Name:  Quotient
 *    Arguments:  Function * fptr1 - Pointer to first function in quotient of form f(x)/g(x)
 *                Function * fptr2 - Pointer to second function in quotient of form f(x)/g(x) 
 *  Description:  Constructer for quotient function f(x)/g(x).
 * =======================================================================================
 */

Quotient::Quotient(Function * fptr1, Function * fptr2) : fptr1{fptr1}, fptr2{fptr2} {
	;
}		/* -----  end of member function Quotient  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Quotient  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the quotient f(x)g(x) at x = arg.
 * =======================================================================================
 */

double Quotient::operator()(const double & arg) const {
	return ((*fptr1)(arg))/((*fptr2)(arg))  ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Quotient  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of quotient f(x)/g(x) at x = arg.
 * =======================================================================================
 */

double Quotient::deriv(const double & arg) const {
	return (-(*fptr1)(arg)*(*fptr2).deriv(arg) + (*fptr2)(arg)*(*fptr1).deriv(arg))/(std::pow((*fptr2)(arg), 2)) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Quotient  ======================================
 *         Name:  ~Quotient
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Quotient::~Quotient() {
	delete fptr1 ;
	delete fptr2 ;
}		/* -----  end of member function   ----- */

}
