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

typedef struct ds_node {
    double *data;
    int top;
} LinkedDoubleStack;

LinkedDoubleStack *ds_create(int size) {
    LinkedDoubleStack *ds = (LinkedDoubleStack *) malloc(sizeof(LinkedDoubleStack));
    ds->data = (double *) malloc(size * sizeof(double));
    ds->top = -1;
    return ds;
}

void ds_push(LinkedDoubleStack *LinkedDoubleStack, double c) {
    LinkedDoubleStack->data[++LinkedDoubleStack->top] = c;
}

double ds_pop(LinkedDoubleStack *s) {
    return s->data[s->top--];
}

double ds_top(LinkedDoubleStack *s) {
    return s->data[s->top];
}

int ds_empty(LinkedDoubleStack *s) {
    return s->top == -1;
}

int ds_size(LinkedDoubleStack *s) {
    return s->top + 1;
}

void ds_print(LinkedDoubleStack *LinkedDoubleStack) {
    for (int i = 0; i <= LinkedDoubleStack->top; i++) {
        printf("%lf ", LinkedDoubleStack->data[i]);
    }
}