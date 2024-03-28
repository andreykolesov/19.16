cmake_minimum_required(VERSION 3.26)
project(untitled3 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled3 main.c
        libs/algorithms/array/array.c
        libs/algorithms/algorithm.c
        libs/algorithms/algorithm.h
        libs/data_structures/bitset/bitset.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/ordered_array_set/ordered_array_set.c
        libs/data_structures/unordered_array_set/unordered_array_set.c
        libs/data_structures/vector/vector.c
        libs/data_structures/vectorVoid/vectorVoid.c)
