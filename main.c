#include <stdio.h>
#include "libs/data_structures/matrix/matrix.h"
#include "libs/algorithms/algorithm.h"
#include <assert.h>

void test_swapMaxMinRows_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {7, 8, 9,
                                                   4, 5, 6,
                                                   1, 2, 3}, 3, 3);

    swapMaxMinRows(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_swapMaxMinRows_2() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              1, 5, 6,
                                              3, 2, 4}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {1, 5, 6,
                                                   7, 8, 9,
                                                   3, 2, 4}, 3, 3);

    swapMaxMinRows(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_swapMaxMinRows() {
    test_swapMaxMinRows_1();
    test_swapMaxMinRows_2();
}

void test_sortRowsByMaxElem_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 9}, 3, 3);

    sortRowsByMaxElem(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortRowsByMaxElem_2() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              1, 5, 6,
                                              3, 2, 4}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {3, 2, 4,
                                                   1, 5, 6,
                                                   7, 8, 9}, 3, 3);

    sortRowsByMaxElem(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortRowsByMaxElem_3() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              9, 5, 6,
                                              9, 2, 4}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {7, 8, 9,
                                                   9, 5, 6,
                                                   9, 2, 4}, 3, 3);

    sortRowsByMaxElem(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortRowsByMaxElem() {
    test_sortRowsByMaxElem_1();
    test_sortRowsByMaxElem_2();
    test_sortRowsByMaxElem_3();
}

void test_sortColsByMinElem_1() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {1, 2, 3,
                                                   4, 5, 6,
                                                   7, 8, 9}, 3, 3);

    sortColsByMinElem(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortColsByMinElem_2() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              5, 1, 6,
                                              8, 7, 4}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {8, 9, 7,
                                                   1, 6, 5,
                                                   7, 4, 8}, 3, 3);

    sortColsByMinElem(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortColsByMinElem_3() {
    matrix m = createMatrixFromArray((int[]) {7, 8, 9,
                                              1, 1, 6,
                                              8, 7, 1}, 3, 3);

    matrix result = createMatrixFromArray((int[]) {7, 8, 9,
                                                   1, 1, 6,
                                                   8, 7, 1}, 3, 3);

    sortColsByMinElem(&m);

    assert (areTwoMatricesEqual(&m, &result));

    freeMemMatrix(&m);
    freeMemMatrix(&result);
}

void test_sortColsByMinElem() {
    test_sortColsByMinElem_1();
    test_sortColsByMinElem_2();
    test_sortColsByMinElem_3();
}

int main() {
    test_swapMaxMinRows();
    test_sortRowsByMaxElem();
    test_sortColsByMinElem();

    return 0;
}