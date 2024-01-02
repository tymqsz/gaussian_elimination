#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

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
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	x = createMatrix(b->r, 1);


	printToScreen(A);
	printToScreen(b);
	/* if (x != NULL) {
		res = backsubst(x,A,b);

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}*/

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
