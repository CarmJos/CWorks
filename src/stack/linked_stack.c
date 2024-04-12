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

#include <malloc.h>
#include <stdio.h>

#define ELEMENT_TYPE double

typedef struct ls_node {
    ELEMENT_TYPE *data;
    int top;
} LinkedStack;

LinkedStack *ls_create(int size) {
    LinkedStack *ds = (LinkedStack *) malloc(sizeof(LinkedStack));
    ds->data = (ELEMENT_TYPE *) malloc(size * sizeof(ELEMENT_TYPE));
    ds->top = -1;
    return ds;
}

void ls_push(LinkedStack *LinkedStack, ELEMENT_TYPE c) {
    LinkedStack->data[++LinkedStack->top] = c;
}

ELEMENT_TYPE ls_pop(LinkedStack *s) {
    return s->data[s->top--];
}

ELEMENT_TYPE ls_top(LinkedStack *s) {
    return s->data[s->top];
}

int ls_empty(LinkedStack *s) {
    return s->top == -1;
}

int ls_size(LinkedStack *s) {
    return s->top + 1;
}

void ls_print(LinkedStack *LinkedStack) {
    for (int i = 0; i <= LinkedStack->top; i++) {
        printf("%lf ", LinkedStack->data[i]);
    }
}