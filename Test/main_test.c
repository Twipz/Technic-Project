#define CTEST_MAIN

#include <stdlib.h>
#include <stdio.h>
#include <func.h>
#include <ctest.h>
#include <time.h>

CTEST(Check, correct_Check) {
    int n = 9;
    int A[9][9] = {{1, 3, 5, 9, 2, 6, 8, 4, 7},
                   {4, 6, 7, 5, 3, 8, 9, 1, 2},
                   {8, 2, 9, 4, 7, 1, 5, 3, 6},
                   {7, 9, 1, 6, 4, 5, 2, 8, 3},
                   {3, 4, 8, 7, 9, 2, 6, 5, 1},
                   {2, 5, 6, 8, 1, 3, 4, 7, 9},
                   {9, 7, 2, 1, 5, 4, 3, 6, 8},
                   {5, 8, 3, 2, 6, 7, 1, 9, 4},
                   {6, 1, 4, 3, 8, 9, 7, 2, 5}};
    int result = Check(A, n);
    int expect = 1;
    ASSERT_EQUAL(expect, result);
}

int main(int argc, const char** argv)  {
    int test_res = ctest_main(argc, argv);
    return test_res;
}
