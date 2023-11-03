#include <stdio.h>

void swap(int *x, int *y) {
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

int main() {

    int a, b, c;
    printf("Please input 3 numbers(split by space): \n");
    scanf("%d %d %d", &a, &b, &c);

    if (b < a) swap(&a, &b);
    if (c < a) swap(&a, &c);
    if (c < b) swap(&b, &c);

    printf("%d < %d < %d", a, b, c);
    return 0;
}
