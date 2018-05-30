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

CTEST(Check, uncorrect_Check) {
    srand(time(NULL));
    int n = 9;
    int A[9][9];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 8 + 1;
        }
    }
    int result = Check(A, n);
    int expect = 0;
    ASSERT_EQUAL(expect, result);
}

CTEST(Check_data, correct_data) {
    int x1 = 9;
    int y1 = 1;
    int number = 0;
    int result = Check_data(x1, y1, number);
    int expect = 1;
    ASSERT_EQUAL(expect, result);
}

CTEST(Check_data, uncorrect_column) {
    int x1 = 10;
    int y1 = 1;
    int number = 0;
    int result = Check_data(x1, y1, number);
    int expect = 0;
    ASSERT_EQUAL(expect, result);
}

CTEST(Check_data, uncorrect_string) {
    int x1 = 9;
    int y1 = 0;
    int number = 0;
    int result = Check_data(x1, y1, number);
    int expect = 0;
    ASSERT_EQUAL(expect, result);
}

CTEST(Check_data, uncorrect_number) {
    int x1 = 9;
    int y1 = 1;
    int number = -1;
    int result = Check_data(x1, y1, number);
    int expect = 0;
    ASSERT_EQUAL(expect, result);
}

int main(int argc, const char** argv)  {
    int test_res = ctest_main(argc, argv);
    return test_res;
}
