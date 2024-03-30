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

void test_sortRowsByMaxElem_1_standard_value() {
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

void test_sortRowsByMaxElem_2_max_value_equal() {
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
    test_sortRowsByMaxElem_1_standard_value();
    test_sortRowsByMaxElem_2_max_value_equal();
}

void test_sortColsByMinElem_1_standard_value() {
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


void test_sortColsByMinElem_2_min_value_equal() {
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
    test_sortColsByMinElem_1_standard_value();
    test_sortColsByMinElem_2_min_value_equal();
}

void test_mulMatrices_1_standard_value() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    matrix result = mulMatrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {30, 36, 42,
                                                  66, 81, 96,
                                                  102, 126, 150}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mulMatrices_2_mul_to_e_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {1, 0, 0,
                                               0, 1, 0,
                                               0, 0, 1}, 3, 3);

    matrix result = mulMatrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mulMatrices_3_mul_to_null_matrix() {
    matrix m1 = createMatrixFromArray((int[]) {1, 2, 3,
                                               4, 5, 6,
                                               7, 8, 9}, 3, 3);

    matrix m2 = createMatrixFromArray((int[]) {0, 0, 0,
                                               0, 0, 0,
                                               0, 0, 0}, 3, 3);

    matrix result = mulMatrices(m1, m2);


    matrix check = createMatrixFromArray((int[]) {0, 0, 0,
                                                  0, 0, 0,
                                                  0, 0, 0}, 3, 3);

    assert(areTwoMatricesEqual(&result, &check));

    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&result);
    freeMemMatrix(&check);
}


void test_mulMatrices() {
    test_mulMatrices_1_standard_value();
    test_mulMatrices_2_mul_to_e_matrix();
    test_mulMatrices_3_mul_to_null_matrix();
}

void test_getSquareOfMatrixIfSymmetric_1_symmetric_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              2, 5, 6,
                                              3, 6, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {14, 30, 42,
                                                  30, 65, 90,
                                                  42, 90, 126}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_getSquareOfMatrixIfSymmetric_2_not_symmetric_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 2, 3,
                                                  4, 5, 6,
                                                  7, 8, 9}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_getSquareOfMatrixIfSymmetric_3_e_matrix() {
    matrix m = createMatrixFromArray((int[]) {1, 0, 0,
                                              0, 1, 0,
                                              0, 0, 1}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 0, 0,
                                                  0, 1, 0,
                                                  0, 0, 1}, 3, 3);

    getSquareOfMatrixIfSymmetric(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_getSquareOfMatrixIfSymmetric() {
    test_getSquareOfMatrixIfSymmetric_1_symmetric_matrix();
    test_getSquareOfMatrixIfSymmetric_2_not_symmetric_matrix();
    test_getSquareOfMatrixIfSymmetric_3_e_matrix();
}

void test_transposeIfMatrixHasNotEqualSumOfRows_1_standard_value() {
    matrix m = createMatrixFromArray((int[]) {1, 2, 3,
                                              4, 5, 6,
                                              7, 8, 9}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 4, 7,
                                                  2, 5, 8,
                                                  3, 6, 9}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transposeIfMatrixHasNotEqualSumOfRows_2_not_different_sum() {
    matrix m = createMatrixFromArray((int[]) {1, 1, 1,
                                              4, 5, 6,
                                              0, 3, 0}, 3, 3);

    matrix check = createMatrixFromArray((int[]) {1, 1, 1,
                                                  4, 5, 6,
                                                  0, 3, 0}, 3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(&m);

    assert(areTwoMatricesEqual(&m, &check));

    freeMemMatrix(&m);
    freeMemMatrix(&check);
}


void test_transpose_if_matrix_has_not_equal_sum_of_rows() {
    test_transposeIfMatrixHasNotEqualSumOfRows_1_standard_value();
    test_transposeIfMatrixHasNotEqualSumOfRows_2_not_different_sum();
}

int main() {
    test_swapMaxMinRows();
    test_sortRowsByMaxElem();
    test_sortColsByMinElem();
    test_mulMatrices();
    test_getSquareOfMatrixIfSymmetric();
    test_transpose_if_matrix_has_not_equal_sum_of_rows();

    return 0;
}