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

typedef struct ds_node {
    double *data;
    int top;
} DoubleStack;

DoubleStack *ds_create(int size) {
    DoubleStack *ds = (DoubleStack *) malloc(sizeof(DoubleStack));
    ds->data = (double *) malloc(size * sizeof(double));
    ds->top = -1;
    return ds;
}

void ds_push(DoubleStack *DoubleStack, double c) {
    DoubleStack->data[++DoubleStack->top] = c;
}

double ds_pop(DoubleStack *s) {
    return s->data[s->top--];
}

double ds_top(DoubleStack *s) {
    return s->data[s->top];
}

int ds_empty(DoubleStack *s) {
    return s->top == -1;
}

int ds_size(DoubleStack *s) {
    return s->top + 1;
}

void ds_print(DoubleStack *DoubleStack) {
    for (int i = 0; i <= DoubleStack->top; i++) {
        printf("%lf ", DoubleStack->data[i]);
    }
}