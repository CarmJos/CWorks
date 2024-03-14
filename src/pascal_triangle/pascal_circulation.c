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

#include <stdio.h>

static int calc(const int a, const int b) {
    return b == 0 || a == b ? 1 : calc(a - 1, b) + calc(a - 1, b - 1);
}

int main() {
    int n = 0;
    printf("Please input the line that want to display: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", calc(i, j));
        }
        printf("\n");
    }

    return 0;
}
