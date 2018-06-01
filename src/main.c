#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "func.h"

int main() {

    char c;
    printf("1. New game\n");
    printf("2. Rules\n");
    printf("3. Exit\n");

    while (c != '3') {
        c = getchar();
        switch(c) {
            case '1': {
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
		    system("clear");
		    if (Check_data(x + 1, y + 1, num) == 1) {
	                A[x][y] = num;
			flag = Check(A, n);
		    }
		    else {
		        printf("You entered wrong parameters.\nTry again.\n");
		    }
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
            
                case '2': {
                    system("clear");
                    FILE *f = fopen("/home/denis/trpo/Kursach/src/file2.txt", "r");
                    char ch;
                    int k = 0;
                    printf(" ");
                    while (!feof(f)) {
                        ch = getc(f);
                        if (ch == ' ') {
                            k++;
                        }
                        if (k == 10) {
                            printf("\n");
	                    k = 0;
	                }
			printf("%c", ch);
		    }
		    printf("\n");
	            fclose(f);
                    break;
                
            }
            case '3': {
                return 0;
            }
        }
    }             
}
