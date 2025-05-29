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
