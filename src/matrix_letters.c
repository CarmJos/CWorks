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

//   *
//  ***
// *****
//*******
// *****
//  ***
//   *
int main() {
    int n = 7;
    int mid = n / 2;
    for (int i = 0; i < n; ++i) {
        int len = i < mid ? i + 1 : n - i;
        for (int j = 0; j < mid - len + 1; ++j) {
            printf(" ");
        }
        for (int j = 0; j < len * 2 - 1; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
