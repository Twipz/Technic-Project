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
    return res;
}
