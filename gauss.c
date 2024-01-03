#include "gauss.h"
#include<stdio.h>
#include<stdlib.h>

#define eps 0.0000001

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
    double pivot;
	int pivot_row;
	double q;

	for(int c = 0; c < mat->c; c++){
		pivot = mat->data[c][c];
		pivot_row = c;
		if(abs(pivot - 0) < eps){
			while(pivot_row < mat->r && mat->data[pivot_row][c] == 0){
				pivot_row++;
			}
			if(pivot_row >= mat->r) return 1;
			
			printf("switching rows\n");
			switch_rows(mat, b, c, pivot_row);
			pivot = mat->data[c][c];
		}
		
		for(int r = c+1; r < mat->r; r++){
			q = mat->data[r][c] / pivot;

			substract_row(mat, b, q, pivot_row, r);
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

int switch_rows(Matrix *mat, Matrix *b, int x, int y){
	if(x > mat->c || y > mat->c || x < 0 || y < 0) return -1;

	double temp;
	for(int i = 0; i < mat->c; i++){
		temp = mat->data[x][i];
		mat->data[x][i] = mat->data[y][i];
		mat->data[y][i] = temp;
	}

	temp = b->data[x][0];
	b->data[x][0] = b->data[y][0];
	b->data[y][0] = temp;

	return 0;

}

