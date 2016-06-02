#ifndef TEST_FUNCS_HPP_R1UKHNW2
#define TEST_FUNCS_HPP_R1UKHNW2

/*
 * =====================================================================================
 *
 *       Filename:  test_funcs.hpp
 *
 *    Description:  File containing test functions for comparison purposes.
 *
 *        Version:  1.0
 *        Created:  19/02/16 16:45:16
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Michael Tierney (MT), tiernemi@tcd.ie
 *
 * =====================================================================================
 */

#include <cmath>
#include <vector>

std::vector<double (*) (const double &)> testFunctions ;
std::vector<double (*) (const double &)> testFunctionsDerivs ;

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_funcs1
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for polynomial 2x
 * =====================================================================================
 */

double test_funcs1(const double & arg) {
	return 2*arg ;
}		/* -----  end of function test_funcs1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_funcs2
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for polynomial 2x - 3x^2 + 4X^3 + 100.5
 * =====================================================================================
 */

double test_funcs2(const double & arg) {
	return 2*arg - 3 *arg*arg + 4*arg*arg*arg + 100.5 ; 
}		/* -----  end of function test_funcs1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_funcs3
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for sum of trigonometric functions Sin(x)+Cos(x)+Tan(x)
 * =====================================================================================
 */

double test_funcs3(const double & arg) {
	return std::sin(arg) + std::cos(arg) + std::tan(arg) ;
}		/* -----  end of function test_funcs1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_funcs1
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for division and hyperbolic functions. 
 *                f(x) = (sinh(x^3) + cosh(x^2))/coth(x)
 * =====================================================================================
 */

double test_funcs4(const double & arg) {
	return( std::sinh(arg*arg*arg) + std::cosh(arg*arg))*tanh(arg) ;
}		/* -----  end of function test_funcs1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_funcs5
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for function ln(exp(x^2 + sin(x)) + 2) ;
 * =====================================================================================
 */

double test_funcs5(const double & arg) {
	return std::log(std::exp(arg*arg+std::sin(arg))+2) ;
}		/* -----  end of function test_funcs1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_funcs6
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for product 3cot^2(x^2) * (3x^2 + 1)
 * =====================================================================================
 */

double test_funcs6(const double & arg) {
	return (3.f/(std::tan(arg*arg)*std::tan(arg*arg))) * (3*arg*arg + 1) ;
}		/* -----  end of function test_funcs1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_deriv1
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for derivative of polynomial 2x
 * =====================================================================================
 */

double test_deriv1(const double & arg) {
	return 2 ;
}		/* -----  end of function test_deriv1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_deriv2
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for derivative of polynomial 2x - 3x^2 + 4X^3 + 100.5
 * =====================================================================================
 */

double test_deriv2(const double & arg) {
	return 2 - 6 *arg + 12*arg*arg ;
}		/* -----  end of function test_deriv1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_deriv3
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for derivative of sum of trigonometric functions Sin(x)+Cos(x)+Tan(x)
 * =====================================================================================
 */

double test_deriv3(const double & arg) {
	return -std::sin(arg) + std::cos(arg) + (1.f + std::tan(arg)*std::tan(arg)) ;
}		/* -----  end of function test_deriv1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_deriv1
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for derivative of division and hyperbolic functions. 
 *                f(x) = (sinh(x^3) + cosh(x^2))/coth(x)
 * =====================================================================================
 */

double test_deriv4(const double & arg) {
	return std::tanh(arg)*(2.f*arg*std::sinh(arg*arg) + 3.f*arg*arg*std::cosh(arg*arg*arg)) +  (1.f/(std::cosh(arg)*std::cosh(arg)))*(std::sinh(arg*arg*arg)+std::cosh(arg*arg)) ;
}		/* -----  end of function test_deriv1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_deriv5
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for derivative of function ln(exp(x^2 + sin(x)) + 2) ;
 * =====================================================================================
 */

double test_deriv5(const double & arg) {
	return  (std::exp(arg*arg+std::sin(arg)) * (2*arg + std::cos(arg)))/ (std::exp(arg*arg+std::sin(arg))+2.f) ;
}		/* -----  end of function test_deriv1  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  test_deriv6
 *    Arguments:  const double & arg - Argument x in function f(x)
 *      Returns:  f(x)
 *  Description:  Test function for derivative of product 3cot^2(x^2) * (3x^2 + 1)
 * =====================================================================================
 */

double test_deriv6(const double & arg) {
	return ((18.f*arg)/(std::tan(arg*arg)*std::tan(arg*arg))) - 12*arg*(3*arg*arg + 1)/(std::tan(arg*arg)*std::sin(arg*arg)*std::sin(arg*arg)) ;
}		/* -----  end of function test_deriv1  ----- */


#endif /* end of include guard: TEST_FUNCS_HPP_R1UKHNW2 */
