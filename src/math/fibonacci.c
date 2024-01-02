#include<stdio.h>

static long long int calc(long long int n) {
    return n <= 2 ? 1 : calc(n - 1) + calc(n - 2);
}

int main() {
    int v;
    printf("Please input the number: \n");
    scanf("%d", &v);
    for (int i = 1; i <= v; ++i) {
        printf("%lld", calc(i));
        if (i % 5 == 0) printf("\n");
        else if (i != v) printf("\t");
    }
    return 0;
}

