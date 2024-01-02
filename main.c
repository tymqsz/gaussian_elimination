#include<iostream>
#include<stdio.h>

int main(){
	int n, m;
	
	/* allocating memory for equations */
	int** A = malloc(sizeof(int*) * n);
	for(int i = 0; i < n; i++){
		A[i] = malloc(sizeof(int) * m);
	}

	int* x = malloc(sizeof(int) * n);
	int* b = malloc(sizeof(int) * n);

	
}

