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
// Created by Karmu on 2024/4/18.
//


#include <malloc.h>
#include "sequence_stack.c"

#define ELEMENT_TYPE int

typedef struct {
    SeqStack *data;
    SeqStack *min_stack;
} MinValueStack;

MinValueStack *mvs_create(int size) {
    MinValueStack *mvs = (MinValueStack *) malloc(sizeof(MinValueStack));
    mvs->data = ss_create(size);
    mvs->min_stack = ss_create(size);
    return mvs;
}

void mvs_push(MinValueStack *mvs, ELEMENT_TYPE c) {
    ss_push(mvs->data, c);
    if (ss_empty(mvs->min_stack) || c <= ss_top(mvs->min_stack)) {
        ss_push(mvs->min_stack, c);
    }
}

ELEMENT_TYPE mvs_pop(MinValueStack *mvs) {
    ELEMENT_TYPE c = ss_pop(mvs->data);
    if (c == ss_top(mvs->min_stack)) {
        ss_pop(mvs->min_stack);
    }
    return c;
}

ELEMENT_TYPE mvs_min(MinValueStack *mvs) {
    return ss_top(mvs->min_stack);
}
