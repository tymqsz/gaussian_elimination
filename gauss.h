#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b, int* x_order);

int switch_rows_and_cols(Matrix *mat, Matrix *b, int* x_order, int row_a, int row_b, int col_a, int col_b);

void substract_row(Matrix *mat, Matrix *b, double q, int pivot_row, int row);

int* best_pivot(Matrix* mat, int p);
#endif
