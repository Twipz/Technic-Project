#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int Check(int A[9][9], int n) {
    int res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j != k) {
                    if (A[i][k] == A[i][j]) {
                        res = 0;
                        break;
                    }
                    if (A[k][i] == A[j][i]) {
                        res = 0;
                        break;
                    }
                }
            }
            if (res == 0) {
                break;
            }
        }
    }
    int B[9], l1 = 0, l2 = 0, k;
    for (l1 = 0; l1 < n; l1 += 3) {
        for (l2 = 0; l2 < n; l2 += 3) {
            k = 0;
            for (int i = l1; i < l1 + 3; i++) {
                for (int j = l2; j < l2 + 3; j++) {
                    B[k] = A[i][j];
                    k++;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i != j) && (B[i] == B[j])) {
                        res = 0;
                    }
                }
            }
        }
    }
    return res;
}
