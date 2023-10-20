// This project is to show how to get the max num in three numbers.
#include <stdio.h>

int max(int x, int y, int z) {
    int s = x;
    if (y > s) s = y;
    if (z > s) s = z;
    return s;
}

int main() {

    printf("Type the numbers that you want to compare (format a,b,c): \n");

    int a, b, c;
    scanf("%d,%d,%d", &a, &b, &c);

    printf("Max num is %d", max(a, b, c));
    return 0;
}
