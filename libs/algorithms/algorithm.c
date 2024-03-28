//
// Created by Андрей on 10.02.2024.
//

#include "algorithm.h"

void swapMaxMinRows(matrix *m){
    position max_value = getMaxValuePos(*m);
    position min_value = getMinValuePos(*m);

    swapRows(*m, max_value.rowIndex, min_value.rowIndex);
}