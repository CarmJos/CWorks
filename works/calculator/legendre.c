#include<stdio.h>

// calculate legendre's n, x value
// n=0, 1
// n=1, Pn(x)  =     x
// n>=1 ( [(2n-1) * x] * Pn-1(x) - [(n-1) * Pn-2(x)] ) / n
static double calc_legendre(const int n, const double x) {
    if (n == 0) return 1;
    if (n == 1) return x;
    return ((2.0 * n - 1.0) * x * calc_legendre(n - 1, x) - (n - 1.0) * calc_legendre(n - 2, x)) / n;
}


int main() {
    int n;
    double x;
    printf("Please input the (n,x): \n");
    scanf("%d,%lf", &n, &x);

    printf("Result -> %lf", calc_legendre(n, x));
    return 0;
}
