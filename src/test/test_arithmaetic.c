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

//
// Created by Karmu on 2024/4/11.
//

#include <stdio.h>
#include "../main/math/arithmetic.c"


int main() {
    // Parser tests
    printf("Transform infix expression to postfix expression:\n");
    printf(" 1 + 2  ->  %s\n", parse_postfix("1 + 2"));
    printf(" 1 - 25  ->  %s\n", parse_postfix("1 - 25"));
    printf(" 21 * 20  ->  %s\n", parse_postfix("21 * 20"));
    printf(" 1 / 2  ->  %s\n", parse_postfix("1 / 2"));
    printf(" 1 + 2 * 3  ->  %s\n", parse_postfix("1 + 2 * 3"));
    printf(" 2 + (2 - 3) * 15  ->  %s\n", parse_postfix("2 + (2 - 3) * 15"));


    printf("\n\nTest calculate function:\n");
    printf("1 + 2 = %.2f\n", calculate("1 + 2"));
    printf("1 - 2 = %.2f\n", calculate("1 - 2"));
    printf("1 * 2 = %.2f\n", calculate("1 * 2"));
    printf("1 / 2 = %.2f\n", calculate("1 / 2"));
    printf("1 + 2 * 3 = %.2f\n", calculate("1 + 2 * 3"));
    printf("2 + (2 - 3) * 15 = %.2f\n", calculate("2 + (2 - 3) * 15"));

    return 0;
}