#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main() {
    int n = 9;
    int A[9][9];
    FILE *f1 = fopen("/home/denis/trpo/Kursach/src/file1.txt", "r");
    printf("  | 1 2 3  4 5 6  7 8 9\n");
    printf("--|---------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < n; j++) {
            fscanf(f1, "%1d", &A[i][j]);
            if (j % 3 == 0) {
            printf(" %d ", A[i][j]);
            }
            else {
                printf("%d ", A[i][j]);
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("  |\n");	
        }
    }
    fclose(f1);
}
