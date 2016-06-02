/*
 * =====================================================================================
 *
 *       Filename:  product.cpp
 *
 *    Description:  File containing source code for product function class.
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

#include "product.hpp"
#include <cmath>
#include <iostream>

namespace arb {

/* 
 * ===  MEMBER FUNCTION CLASS : Product  ===================================================
 *         Name:  Product
 *    Arguments:  Function * fptr1 - Pointer to first function in product of form f(x)g(x)
 *                Function * fptr2 - Pointer to second function in product of form f(x)g(x) 
 *  Description:  Constructer for product function f(x)g(x).
 * =======================================================================================
 */

Product::Product(Function * fptr1, Function * fptr2) : fptr1{fptr1}, fptr2{fptr2} {
	;
}		/* -----  end of member function Product  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Product  ====================================================
 *         Name:  operator()
 *    Arguments:  const double & arg - Argument x passed to function of one variable f(x).
 *      Returns:  The value of f(arg).
 *  Description:  Evaluates the product f(x)g(x) at x = arg.
 * =======================================================================================
 */

double Product::operator()(const double & arg) const {
	return ((*fptr1)(arg))*((*fptr2)(arg))  ;
}		/* -----  end of member function ::operat  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Product  ==================================================
 *         Name:  deriv
 *    Arguments:  const double & arg - Argument x passed to function of one variable f'(x).
 *      Returns:  The value of f'(arg).
 *  Description:  Evaluates the derivative of product f(x)g(x) at x = arg.
 * =======================================================================================
 */

double Product::deriv(const double & arg) const {
	return (*fptr1)(arg)*(*fptr2).deriv(arg) + (*fptr2)(arg)*(*fptr1).deriv(arg) ;
}		/* -----  end of member function deriv  ----- */

/* 
 * ===  MEMBER FUNCTION CLASS : Product  ======================================
 *         Name:  ~Product
 *  Description:  Destructor for class.
 * =====================================================================================
 */

Product::~Product() {
	delete fptr1 ;
	delete fptr2 ;
}		/* -----  end of member function   ----- */

}
