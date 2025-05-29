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

// Insert a number into a array depends on its own order;

int main() {
    int arr[10] = {4, 11, 36, 71, 352, 953};

    int num;
    printf("Please input a number: \n");
    scanf("%d", &num);

    int i = 0;
    while (i < 9 && num > arr[i]) {
        ++i;
    }

    for (int j = 9; j > i; --j) {
        arr[j] = arr[j - 1];
    }

    arr[i] = num;

    for (int j = 0; j < 10; ++j) {
        if (arr[j] != 0)printf("%d ", arr[j]);
    }
    
    return 0;
}
