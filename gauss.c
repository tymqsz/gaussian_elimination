#include "gauss.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define eps 0.0000001
#define inf 10000000000000000
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b, int* x_order){
    double pivot;
	double q;
	int* p_index;
	
	for(int c = 0; c < mat->c; c++){
		p_index = best_pivot(mat, c);
		if(p_index[0] == -1) return 1;
		else{
			switch_rows_and_cols(mat, b, x_order, c, p_index[0], c, p_index[1]);
		}
		
		pivot = mat->data[c][c];
		for(int r = c+1; r < mat->r; r++){
			q = mat->data[r][c] / pivot;

			substract_row(mat, b, q, c, r);
		}
	}
	
	return 0;
}

void substract_row(Matrix *mat, Matrix *b, double q, int pivot_row, int row){
	printf("substracting row %d * %lf from row %d\n", pivot_row, q, row);
	for(int i = 0; i < mat->c; i++){
		mat->data[row][i] -= (mat->data[pivot_row][i]*q);
	}

	b->data[row][0] -= (b->data[pivot_row][0]*q);
}

int switch_rows_and_cols(Matrix *mat, Matrix *b, int* x_order, int row_a, int row_b, int col_a, int col_b){
	if(col_a > mat->c || col_b > mat->c || col_a < 0 || col_b < 0) return -1;
	if(row_a > mat->r || row_b > mat->r || row_a < 0 || row_b < 0) return -1;

	double temp;
	/* switching rows */
	for(int i = 0; i < mat->c; i++){
		temp = mat->data[row_a][i];
		mat->data[row_a][i] = mat->data[row_b][i];
		mat->data[row_b][i] = temp;
	}
	temp = b->data[row_a][0];
	b->data[row_a][0] = b->data[row_b][0];
	b->data[row_b][0] = temp;

	/* switching cols */
	for(int i = 0; i < mat->r; i++){
		temp = mat->data[i][col_a];
		mat->data[i][col_a] = mat->data[i][col_b];
		mat->data[i][col_b] = temp;
	}

	/* saving x vector order */
	int temp_i;
	temp_i = x_order[col_a];
	x_order[col_a] = x_order[col_b];
	x_order[col_b] = temp_i;


	return 0;

}

int* best_pivot(Matrix* mat, int p){
	int* res = malloc(sizeof(int)*2);
	double max_piv = 0;
	int row = -1, col = -1;

	for(int r = p; r < mat->r; r++){
		for(int c = p; c < mat->c; c++){
			if(fabs(mat->data[r][c]) > max_piv){
				max_piv = abs(mat->data[r][c]);
				row = r;
				col = c;
			}
		}
	}
	res[0] = row;
	res[1] = col;

	return res;
}










































