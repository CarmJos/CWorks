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
#include <stdio.h>
#include <stdbool.h>

#define ELEMENT_TYPE int

// 双向共享栈
typedef struct ss_node {
    ELEMENT_TYPE *data;

    int left;
    int right;

    int size;
} SharedStack;

SharedStack *ss_create(int size) {
    SharedStack *ds = (SharedStack *) malloc(sizeof(SharedStack));
    ds->data = (ELEMENT_TYPE *) malloc(size * sizeof(ELEMENT_TYPE));
    ds->left = -1;
    ds->right = size;
    ds->size = size;
    return ds;
}

bool ss_full(SharedStack *SharedStack) {
    return SharedStack->left + 1 == SharedStack->right;
}

bool ss_push(SharedStack *SharedStack, ELEMENT_TYPE c, bool left) {
    if (ss_full(SharedStack)) return false;
    if (left) {
        SharedStack->data[++SharedStack->left] = c;
    } else {
        SharedStack->data[--SharedStack->right] = c;
    }
    return true;
}

bool ss_empty(SharedStack *SharedStack, bool left) {
    if (left) {
        return SharedStack->left == -1;
    } else {
        return SharedStack->right == SharedStack->size;
    }
}

ELEMENT_TYPE ss_pop(SharedStack *SharedStack, bool left) {
    if (ss_empty(SharedStack, left)) return -1;
    if (left) {
        return SharedStack->data[SharedStack->left--];
    } else {
        return SharedStack->data[SharedStack->right++];
    }
}

void ss_clear(SharedStack *SharedStack) {
    SharedStack->left = -1;
    SharedStack->right = SharedStack->size;
}

void ss_print(SharedStack *SharedStack) {
    if (ss_empty(SharedStack, 1)) {
        printf("Left stack is empty.\n");
    } else {
        printf("Left stack: ");
        for (int i = 0; i <= SharedStack->left; i++) {
            printf("%d ", SharedStack->data[i]);
        }
        printf("\n");
    }

    if (ss_empty(SharedStack, 0)) {
        printf("Right stack is empty.\n");
    } else {
        printf("Right stack: ");
        for (int i = SharedStack->size - 1; i >= SharedStack->right; i--) {
            printf("%d ", SharedStack->data[i]);
        }
        printf("\n");
    }
}
