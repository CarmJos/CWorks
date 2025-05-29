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


int cube(int v) {
    return v * v * v;
}

int calc(int v) {
    return (cube(v % 10) + cube(v / 10 % 10) + cube(v / 100 % 10));
}

int main() {
    int i = 100;

    while (i < 1000) {
        if (i == calc(i)) {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}

