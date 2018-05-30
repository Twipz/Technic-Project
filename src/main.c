#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "func.h"

int main() {
    srand(time(NULL));
    int n = 9, x, y, num;
    int A[9][9];
    bool flag = 0;
    FILE *f1 = fopen("/home/denis/trpo/Kursach/src/file1.txt", "r");
    system("clear");
    printf("    1 2 3   4 5 6   7 8 9  \n");
    printf("  |------------------------\n");
    for (int i = 0; i < n; i++) {
        printf(" %d|", i + 1);
        for (int j = 0; j < n; j++) {
            fscanf(f1, "%1d", &A[i][j]);
            if (A[i][j] != 0) {
                if ((j + 1) % 3 == 0) {
                    printf(" %d |", A[i][j]);
                }
                else {
                    printf(" %d", A[i][j]);
                }
            }
            else {
                if ((j + 1) % 3 == 0) {
                    printf("   |");
                }
                else {
                    printf("  ");
                }
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("  -------------------------\n");	
        }
    }
    fclose(f1);
    while (flag == 0) {
        printf("Enter column number:\n");
        scanf("%d", &x);
        printf("Enter string number:\n");
        scanf("%d", &y);
        x--; y--;
        printf("Enter the number you want to put in the cell:\n");
        scanf("%d", &num);
        A[x][y] = num;
        flag = Check(A, n);
        system("clear");
        printf("    1 2 3   4 5 6   7 8 9  \n");
        printf("  |------------------------\n");
        for (int i = 0; i < n; i++) {
            printf(" %d|", i + 1);
            for (int j = 0; j < n; j++) {
                if (A[i][j] != 0) {
                    if ((j + 1) % 3 == 0) {
                        printf(" %d |", A[i][j]);
                    }
                    else {
                        printf(" %d", A[i][j]);
                    }
                }
                else {
                    if ((j + 1) % 3 == 0) {
                        printf("   |");
                    }
                    else {
                        printf("  ");
                    }
                }
            }
            printf("\n");
            if ((i + 1) % 3 == 0) {
                printf("  -------------------------\n");	
            }
        }
    }
    printf("Congratulations!!! You won!!!\n");
}
