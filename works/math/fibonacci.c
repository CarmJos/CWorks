#include<stdio.h>

static long long int calc(long long int n) {
    return n <= 2 ? 1 : calc(n - 1) + calc(n - 2);
}

int main() {
    int v;
    printf("Please input the number: \n");
    scanf("%d", &v);
    printf("Result -> %lld", calc(v));
    return 0;
}

