#include "backsubst.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define eps 0.000001

int backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	if(x->r != mat->c || b->r != mat->c) return 2;
 	for (int i = 0; i < x->r; i++) {
        x->data[i][0] = b->data[i][0];
    }
	
	double prev = 0.0;
	for(int r = mat->r-1; r >= 0; r--){
		if(fabs(mat->data[r][r] - 0)  < eps) return 1;
		
		prev = scalar_mul(mat, x, r) - mat->data[r][r]*x->data[r][0];
		x->data[r][0] = (b->data[r][0]-prev)/mat->data[r][r];
	}

    return 0;
}

double scalar_mul(Matrix *mat, Matrix *x, int row){
	double sum = 0.0;

	for(int i = 0; i < mat->c; i++){
		sum += (mat->data[row][i]*x->data[i][0]);
	}

	return sum;
}

