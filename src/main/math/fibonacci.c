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

