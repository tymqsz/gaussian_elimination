#ifndef _GAUSS_H
#define _GAUSS_H

#include "mat_io.h"

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b);

int switch_rows(Matrix *mat, Matrix *b, int x, int y);

void substract_row(Matrix *mat, Matrix *b, double q, int pivot_row, int row);

int best_row(Matrix* mat, int col);
#endif
