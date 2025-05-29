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
#include <stdbool.h>

#define ELEMENT_TYPE int

typedef struct ss_node {
    ELEMENT_TYPE *data;
    int size;
    int top;
} SeqStack;

bool ss_empty(SeqStack *s) {
    return s->top == -1;
}

bool ss_full(SeqStack *s) {
    return s->top == s->size - 1;
}

SeqStack *ss_create(int size) {
    SeqStack *ds = (SeqStack *) malloc(sizeof(SeqStack));
    ds->data = (ELEMENT_TYPE *) malloc(size * sizeof(ELEMENT_TYPE));
    ds->size = size;
    ds->top = -1;
    return ds;
}

void ss_push(SeqStack *stack, ELEMENT_TYPE c) {
    stack->data[++stack->top] = c;
}


ELEMENT_TYPE ss_pop(SeqStack *s) {
    return s->data[s->top--];
}

ELEMENT_TYPE ss_top(SeqStack *s) {
    return s->data[s->top];
}

int ss_size(SeqStack *s) {
    return s->top + 1;
}

void ss_print(SeqStack *stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
}