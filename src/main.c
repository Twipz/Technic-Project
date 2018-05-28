#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"

int main() {
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

    printf("  | 1 2 3  4 5 6  7 8 9\n");
    printf("--|---------------------\n");
    for (int i = 0; i < n; i++) {
	printf("%d |", i + 1);
        for (int j = 0; j < n; j++) {
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
}
