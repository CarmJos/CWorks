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

#include <malloc.h>
#include <stdio.h>

typedef struct stack_node {
    char *data;
    int top;
} LinkedStringStack;

LinkedStringStack *s_create(int size) {
    LinkedStringStack *stack = (LinkedStringStack *) malloc(sizeof(LinkedStringStack));
    stack->data = (char *) malloc(size * sizeof(char));
    stack->top = -1;
    return stack;
}

void s_push(LinkedStringStack *stack, char c) {
    stack->data[++stack->top] = c;
}

char s_pop(LinkedStringStack *stack) {
    return stack->data[stack->top--];
}

char s_top(LinkedStringStack *stack) {
    return stack->data[stack->top];
}

int s_empty(LinkedStringStack *stack) {
    return stack->top == -1;
}

int s_size(LinkedStringStack *stack) {
    return stack->top + 1;
}

void s_print(LinkedStringStack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%c ", stack->data[i]);
    }
}