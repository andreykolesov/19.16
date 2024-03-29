#ifndef UNTITLED_ALGORITHM_H
#define UNTITLED_ALGORITHM_H

#include "../data_structures/matrix/matrix.h"

// меняет местами строки матрицы m, в которых находятся максимальный и минимальный элементы
void swapMaxMinRows(matrix *m);

// сортирует строки матрицы m по неубыванию наибольших элементов строк
void sortRowsByMaxElem(matrix *m);

// сортирует столбцы матрицы по неубыванию минимальных элементов столбцов
void sortColsByMinElem(matrix *m);

#endif
