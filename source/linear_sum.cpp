/*
 * =====================================================================================
 *
 *       Filename:  linear_sum.cpp
 *
 *    Description:  File containing source code for linearSum function class.
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

#include "linear_sum.hpp"
#include <cmath>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : LinearSum  ===================================================
 *         Name:  LinearSum
 *    Arguments:  Function * fptr1 - Pointer to first function in linearSum of form f(x)+g(x)
 *                Function * fptr2 - Pointer to second function in linearSum of form f(x)+g(x) 
 *  Description:  Constructer for linearSum function f(x)+g(x).
 * =======================================================================================
 */

LinearSum::LinearSum(Function * fptr1, Function * fptr2) : fptr1{fptr1}, fptr2{fptr2} {
	;
}		/* -----  end of member function LinearSum  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : LinearSum  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the linearSum f(x)+g(x) at x = arg.
 * =======================================================================================
 */

double LinearSum::operator()(const double & arg) const {
	return ((*fptr1)(arg))+((*fptr2)(arg))  ;
}		/* -----  end of member function ::operation()  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : LinearSum  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of linearSum f(x)+g(x) at x = arg.
 * =======================================================================================
 */

double LinearSum::deriv(const double & arg) const {
	return (*fptr2).deriv(arg) + (*fptr1).deriv(arg) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : LinearSum  ======================================
 *         Name:  ~LinearSum
 *  Description:  Destructor for class.
 * =====================================================================================
 */

LinearSum::~LinearSum() {
	delete fptr1 ;
	delete fptr2 ;
}		/* -----  end of member function   ----- */

}
