#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

void fix_x_order(int* x_order, Matrix* x){
	double* fixed_x = malloc(sizeof(double)*x->r);
	
	for(int i = 0; i < x->r; i++){
		fixed_x[x_order[i]] = x->data[i][0];
	}

	for(int i = 0; i < x->r; i++){
		x->data[i][0] = fixed_x[i];
	}
}

int main(int argc, char ** argv) {
	char* pa = malloc(100);
	char* pb = malloc(100);
	strcpy(pa, "lmp9/trunk/dane/A");
	strcpy(pb, "lmp9/trunk/dane/b");

	char* A_file = argc > 1 ? argv[1] : pa;
	char* b_file = argc > 2 ? argv[2] : pb;
	int res;

	Matrix * A = readFromFile(A_file);
	Matrix * b = readFromFile(b_file);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	
	int* x_order = malloc(sizeof(int)*A->c);
	for(int i = 0; i < A->c; i++){
		x_order[i] = i;
	}

	res = eliminate(A,b, x_order);
	if(res == 1){
		printf("macierz osobliwa, brak rozwiazania\n");
		return 0;
	}

	x = createMatrix(b->r, 1);

	printf("solution:\n");
	if (x != NULL) {
		res = backsubst(x,A,b);
		fix_x_order(x_order, x);
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}
	
	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
