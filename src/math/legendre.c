// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2024. CarmJos
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
