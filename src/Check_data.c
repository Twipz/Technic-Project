#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "func.h"

int Check_data(int x, int y, int num) {
    int res = 0;
    if ((x >= 1) && (x <= 9) && (y >= 1) && (y <= 9) && (num >= 0) && (num <= 9)) {
        res = 1;
    }
    return res;
}
