/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

/** @defgroup InvBasicMath InvBasicMath
	@brief This file contains basic (overloadable) math functions and macros
    @ingroup EmbUtils
    @{
*/

#ifndef _INV_BASIC_MATH_H_
#define _INV_BASIC_MATH_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @brief  Return absolute value of argument
*/
#ifndef INV_ABS
#	define INV_ABS(a)		((a) < 0 ? -(a) : (a))
#endif

/** @brief  Return minimum of two arguments
*/
#ifndef INV_MIN
#	define INV_MIN(a, b)	((a) < (b) ? (a) : (b))
#endif

/** @brief  Return maximum of two arguments
*/
#ifndef INV_MAX
#	define INV_MAX(a, b)	((a) > (b) ? (a) : (b))
#endif

/** @brief  Define value for pi
*/
#ifndef INV_PI
#   define INV_PI 3.14159265358979
#endif
#ifndef M_PI
#	define M_PI INV_PI
#endif
  
/** @brief  Return saturated integer
*/
#ifndef INV_SATURATE
static inline long InvBasicMath_saturatel(long in, long min, long max)
{
	if (in > max)
		return max;
	else if (in < min)
		return min;
	else
		return in;
}
#	define INV_SATURATE(a, min, max) 	InvBasicMath_saturatel(a, min, max)
#endif

/** @brief  Compute log2 from integer
*/
#ifndef INV_LOG2
unsigned int InvBasicMath_log2u(unsigned int val);
#	define INV_LOG2(a)		InvBasicMath_log2u(a)
#endif

/** @brief Check if matrix is orthonormal
*   @param [in] matrix 3x3 Matrix to be checked
*   @return 1 if it is an orthonormal matrix, 0 otherwise
*/
int InvBasicMath_isAnOrthonormalMatrix(const float matrix[9]);

/** @brief Compute the determinant of the matrix
*   @param [in] matrix 3x3 Matrix to be checked
*   @return the determinant value
*/
float InvBasicMath_computeMatrixDeterminant(const float matrix[9]);

#ifdef __cplusplus
}
#endif

#endif /* _INV_BASIC_MATH_H_ */

/** @} */

