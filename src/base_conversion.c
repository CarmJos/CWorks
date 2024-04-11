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

#include "list/linked_stack.h"

// 使用栈实现进制转换

char *convert(int num, int base) {

    Stack *stack = s_create(100);
    while (num != 0) {
        s_push(stack, num % base);
        num /= base;
    }

    char *result = (char *) malloc(100 * sizeof(char));
    int index = 0;
    while (!s_empty(stack)) {
        result[index++] = s_pop(stack) + '0';
    }
    result[index] = '\0';
    free(stack);
    return result;
}

void convert_print(int num, int base) {

    Stack *stack = s_create(100);
    while (num != 0) { // Push the remainder to the stack
        s_push(stack, num % base);
        num /= base;
    }

    s_print(stack); // Print the stack
    while (!s_empty(stack)) { // Print the result
        printf("%d", s_pop(stack));
    }

    free(stack);
}


int main() {


    int num, base;
    printf("Please input a number: ");
    scanf("%d", &num);

    printf("\n");
    printf("Please input the base: ");
    scanf("%d", &base);

    char *result = convert(num, base);
    printf("%s\n", result);
    convert_print(num, base);

    free(result);
    return 0;
}