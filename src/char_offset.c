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

#define OFFSET 4

char offset(char input) {
    return (char) (input + OFFSET);
}

int main() {

    printf("Please input the code that want to offset:\n");

    char c1 = getchar();
    char c2 = getchar();
    char c3 = getchar();
    char c4 = getchar();
    char c5 = getchar();

    putchar(offset(c1));
    putchar(offset(c2));
    putchar(offset(c3));
    putchar(offset(c4));
    putchar(offset(c5));
    printf("\n");

    printf("%c%c%c%c%c", offset(c1), offset(c2), offset(c3), offset(c4), offset(c5));

    return 0;
}
