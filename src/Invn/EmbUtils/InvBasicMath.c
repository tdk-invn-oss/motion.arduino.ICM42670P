/*
    Copyright (c) 2014-2015 InvenSense Inc. Portions Copyright (c) 2014-2015 Movea. All rights reserved.

    This software, related documentation and any modifications thereto (collectively "Software") is subject
    to InvenSense and its licensors' intellectual property rights under U.S. and international copyright and
    other intellectual property rights laws.

    InvenSense and its licensors retain all intellectual property and proprietary rights in and to the Software
    and any use, reproduction, disclosure or distribution of the Software without an express license
    agreement from InvenSense is strictly prohibited.
*/

#include "InvBasicMath.h"

#include <limits.h>

unsigned int InvBasicMath_log2u(unsigned int val)
{
	unsigned int ret = UINT_MAX;

	while (val != 0) {
		val >>= 1;
		ret++;
	}

	return ret;
}

int InvBasicMath_isAnOrthonormalMatrix(const float matrix[9])
{
	// Check if matrix is orthogonal
	// Matrix is orthogonal if transpose(Matrix) x Matrix = Identity

	float transpose[9];
	float mult[9];
	int i, j;

	// Compute Transpose(matrix)
	for (i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			transpose[i*3+j] = matrix[i+j*3];
		}
	}

	// Mulitply transpose x matrix
	mult[0] = transpose[0]*matrix[0] + transpose[1]*matrix[3] + transpose[2]*matrix[6];
	mult[1] = transpose[0]*matrix[1] + transpose[1]*matrix[4] + transpose[2]*matrix[7];
	mult[2] = transpose[0]*matrix[2] + transpose[1]*matrix[5] + transpose[2]*matrix[8];

	mult[3] = transpose[3]*matrix[0] + transpose[4]*matrix[3] + transpose[5]*matrix[6];
	mult[4] = transpose[3]*matrix[1] + transpose[4]*matrix[4] + transpose[5]*matrix[7];
	mult[5] = transpose[3]*matrix[2] + transpose[4]*matrix[5] + transpose[5]*matrix[8];

	mult[6] = transpose[6]*matrix[0] + transpose[7]*matrix[3] + transpose[8]*matrix[6];
	mult[7] = transpose[6]*matrix[1] + transpose[7]*matrix[4] + transpose[8]*matrix[7];
	mult[8] = transpose[6]*matrix[2] + transpose[7]*matrix[5] + transpose[8]*matrix[8];

	// Check that mult is identity
	for (i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if (i == j) {
				if (mult[i+j*3] != 1)
					return 0;
			}
			else {
				if (mult[i+j*3] != 0)
					return 0;
			}
		}
	}

	return 1;
}

float InvBasicMath_computeMatrixDeterminant(const float matrix[9])
{
	return matrix[0] * (matrix[4]*matrix[8] - matrix[7]*matrix[5])
	      -matrix[1] * (matrix[3]*matrix[8] - matrix[6]*matrix[5])
	      +matrix[2] * (matrix[3]*matrix[7] - matrix[4]*matrix[6]);
}


