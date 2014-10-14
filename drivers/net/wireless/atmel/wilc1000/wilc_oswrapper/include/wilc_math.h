#ifndef __WILC_MATH_H__
#define __WILC_MATH_H__

/*!  
*  @file	WILC_Math.h
*  @brief	Math Operations OS wrapper functionality
*  @author	remil
*  @sa		WILC_OSWrapper.h top level OS wrapper file
*  @date	2 Nov 2010
*  @version	1.0
*/

#ifndef CONFIG_WILC_MATH_OPERATIONS_FEATURE
#error the feature CONFIG_WILC_MATH_OPS_FEATURE must be supported to include this file
#endif



/**
*  @brief 		Returns the arc cosine of x in radians.
*  @details 	Returns the arc cosine of x in radians.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		The value x must be within the range of -1 to +1 (inclusive).
				The returned value is in the range of 0 to pi (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_acos(WILC_Double x);

/**
*  @brief 		Returns the arc sine of x in radians.
*  @details 	Returns the arc sine of x in radians.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		The value x must be within the range of -1 to +1 (inclusive).
				The returned value is in the range of 0 to pi (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_asin(WILC_Double x);

/**
*  @brief 		Returns the arc tangent of x in radians.
*  @details 	Returns the arc tangent of x in radians.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		The value of x has no range. 
				The returned value is in the range of -p/2 to +p/2 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_atan(WILC_Double x);

/**
*  @brief 		Returns the arc tangent in radians
*  @details 	Returns the arc tangent in radians of y/x based on the
				signs of both values to determine the correct quadrant.
*  @param[in] 	WILC_Double x
*  @param[in] 	WILC_Double y
*  @return 		WILC_Double 
*  @note 		Both y and x cannot be zero.
				The returned value is in the range of -p/2 to +p/2 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_atan2(WILC_Double y, WILC_Double x);


/**
*  @brief 		Returns the cosine of a radian angle x.
*  @details 	Returns the cosine of a radian angle x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		The value of x has no range.
				The returned value is in the range of -1 to +1 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_cos(WILC_Double x);


/**
*  @brief 		Returns the hyperbolic cosine of x.
*  @details 	Returns the hyperbolic cosine of x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_cosh(WILC_Double x);


/**
*  @brief 		Returns the sine of a radian angle x.
*  @details 	Returns the sine of a radian angle x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		The value of x has no range.
				The returned value is in the range of -1 to +1 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_sin(WILC_Double x);


/**
*  @brief 		Returns the hyperbolic sine of x.
*  @details 	Returns the hyperbolic sine of x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_sinh(WILC_Double x);
/**
*  @brief 		Returns the tangent of a radian angle x.
*  @details 	Returns the tangent of a radian angle x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_tan(WILC_Double x);

/**
*  @brief 		Returns the hyperbolic tangent of x.
*  @details 	Returns the hyperbolic tangent of x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		The value of x has no range.
				The returned value is in the range of -1 to +1 (inclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_tanh(WILC_Double x);


/**
*  @brief 		Returns the value of e raised to the xth power.
*  @details 	Returns the value of e raised to the xth power.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_exp(WILC_Double x);

/**
*  @brief 		The returned value is the mantissa and the integer pointed to by exponent is the exponent.
*  @details 	The returned value is the mantissa and the integer pointed to by exponent is the exponent.
				The resultant value is x=mantissa * 2^exponent.
*  @param[in] 	WILC_Double x
*  @param[out] 	WILC_Sint32* exponent
*  @return 		WILC_Double 
*  @note 		The mantissa is in the range of .5 (inclusive) to 1 (exclusive).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_frexp(WILC_Double x, WILC_Sint32* exponent);



/**
*  @brief 		Returns x multiplied by 2 raised to the power of exponent.
*  @details 	Returns x multiplied by 2 raised to the power of exponent.
				x*2^exponent
*  @param[in] 	WILC_Double x
*  @param[out] 	WILC_Sint32 exponent
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_ldexp(WILC_Double x, WILC_Sint32 exponent);


/**
*  @brief 		Returns the natural logarithm (base-e logarithm) of x.
*  @details 	Returns the natural logarithm (base-e logarithm) of x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_log(WILC_Double x);


/**
*  @brief 		Returns the common logarithm (base-10 logarithm) of x.
*  @details 	Returns the common logarithm (base-10 logarithm) of x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_log10(WILC_Double x);


/**
*  @brief 		Breaks the floating-point number x into integer and fraction components.
*  @details 	Breaks the floating-point number x into integer and fraction components.
				The returned value is the fraction component (part after the decimal),
				and sets integer to the integer component.

*  @param[in] 	WILC_Double x
*  @param[out] 	WILC_Double* dInteger
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_modf(WILC_Double x,WILC_Double* dInteger);



/**
*  @brief 		Returns x raised to the power of y.
*  @details 	Returns x raised to the power of y.
*  @param[in] 	WILC_Double x
*  @param[in] 	WILC_Double y
*  @return 		WILC_Double 
*  @note 		x cannot be negative if y is a fractional value.
				x cannot be zero if y is less than or equal to zero.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_pow(WILC_Double x,WILC_Double y);



/**
*  @brief 		Returns the square root of x.
*  @details 	Returns the square root of x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		The argument cannot be negative. The returned value is always positive.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_sqrt(WILC_Double x);

/**
*  @brief 		Returns the smallest integer value greater than or equal to x.
*  @details 	Returns the smallest integer value greater than or equal to x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_ceil(WILC_Double x);

/**
*  @brief 		Returns the absolute value of x
*  @details 	Returns the absolute value of x 
				(a negative value becomes positive, positive value is unchanged).
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument.
				The return value is always positive.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_fabs(WILC_Double x);

/**
*  @brief 		Returns the largest integer value less than or equal to x.
*  @details 	Returns the largest integer value less than or equal to x.
*  @param[in] 	WILC_Double x
*  @return 		WILC_Double 
*  @note 		There is no range limit on the argument or return value.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_floor(WILC_Double x);

/**
*  @brief 		Returns the remainder of x divided by y.
*  @details 	Returns the remainder of x divided by y.
*  @param[in] 	WILC_Double x
*  @param[in] 	WILC_Double y
*  @return 		WILC_Double 
*  @note 		There is no range limit on the return value. 
				If y is zero, then either a range error will occur or the function 
				will return zero (implementation-defined).
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Double WILC_fmod(WILC_Double x,WILC_Double y);


/**
*  @brief 		
*  @details 	Returns the absolute value of x. 
				Note that in two's compliment that the most maximum number cannot be 
				represented as a positive number. The result in this case is undefined.
				The absolute value is returned.
*  @param[in] 	WILC_Sint32 x
*  @return 		WILC_Sint32 
*  @note 		
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Sint32 WILC_abs(WILC_Sint32 x);




/**
*  @brief 		
*  @details 	Returns a pseudo-random number in the range of 0 to RAND_MAX.
*  @return 		WILC_Sint32 
*  @note 		
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
WILC_Sint32 WILC_rand();


/**
*  @brief 		
*  @details 	This function seeds the random number generator used by the function rand.
				Seeding srand with the same seed will cause rand to return the same sequence
				of pseudo-random numbers.
				If srand is not called, WILC_rand acts as if WILC_srand(1) has been called.

*  @param[in] 	WILC_Uint32 seed
*  @note 		No value is returned.
*  @author		remil
*  @date		2 Nov 2010
*  @version		1.0
*/
void WILC_srand(WILC_Uint32 seed);



#endif
