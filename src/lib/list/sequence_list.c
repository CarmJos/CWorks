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

#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"

#define INITIATE_SIZE 10
#define  ELEMENT_TYPE int // 定义数据类型

typedef struct {
    ELEMENT_TYPE *data;
    int size;
    int capacity;
} SeqList;

// Create an empty list
static SeqList *sl_create() {
    SeqList *list = (SeqList *) malloc(sizeof(SeqList));
    list->data = (ELEMENT_TYPE *) malloc(INITIATE_SIZE * sizeof(int));
    list->size = 0;
    list->capacity = INITIATE_SIZE;
    return list;
}

// Expand the list's capacity
static void sl_expand(SeqList *l) {
    ELEMENT_TYPE *new_data = (ELEMENT_TYPE *) malloc(l->capacity * 2 * sizeof(int));
    for (int i = 0; i < l->size; i++) {
        new_data[i] = l->data[i];
    }
    free(l->data);
    l->data = new_data;
    l->capacity *= 2;
}

// Shrink the list's capacity
static void sl_shrink(SeqList *l, int amount) {
    int after = l->capacity - amount;
    ELEMENT_TYPE *new_data = (ELEMENT_TYPE *) malloc(after * sizeof(int));
    l->size = l->size > after ? after : l->size;
    for (int i = 0; i < l->size; i++) {
        new_data[i] = l->data[i];
    }
    free(l->data);
    l->data = new_data;
    l->capacity = after;
}

// Put the whole array into the list, return success or not.
static bool sl_put(SeqList *l, const ELEMENT_TYPE *array, int length) {
    while (length > l->capacity) {
        sl_expand(l); // Expand the list
    }

    for (int k = 0; k < length; k++) {
        l->data[k] = array[k];
    }
    l->size = length;
    return 1;
}

// Check if the list is empty, return success or not.
static bool sl_empty(SeqList *l) {
    return l->size == 0;
}

// Out convert_print the whole list
static void sl_print(SeqList *l) {
    for (int i = 0; i < l->size; i++)
        printf("%d ", (l->data[i]));
}

// Get the index of the target, -1 if not contains
static int sl_index(SeqList *l, int target) {
    for (int i = 0; i < l->size; i++) {
        if (l->data[i] == target) {
            return i + 1;
        }
    }
    return -1;
}

// Check if the target contains in the list, return success or not.
static bool sl_contains(SeqList *l, int target) {
    for (int i = 0; i < l->size; i++) {
        if (l->data[i] == target) {
            return true;
        }
    }
    return false;
}

// Get the index of the index to result, return success or not.
static bool sl_get(SeqList *list, int index, ELEMENT_TYPE *result) {
    if (index < 1 || index > list->size) {
        return false;
    } else {
        *result = list->data[index];
        return true;
    }
}

// Add the element to the list, return success or not.
static bool sl_add(SeqList *list, int element) {
    if (list->size >= list->capacity) {
        sl_expand(list);
    }

    list->data[list->size] = element;
    list->size++;

    return true;
}

// Insert the element into the target index, return success or not.
static bool sl_insert(SeqList *list, int index, int element) {
    if (list->size >= list->capacity) {
        sl_expand(list);
    }

    if (index < 0) {
        return false; // Wrong index
    }

    if (index > list->size) {
        // If the index is larger than the size, put it at the end
        index = list->size;
    }

    for (int k = list->size; k > index; k--) {
        list->data[k] = list->data[k - 1];
    }

    list->data[index] = element;
    list->size++;

    return true;
}

// Remove the element at the index, return success or not.
static bool sl_remove(SeqList *list, int index) {
    if (list->size == 0) {
        return false;
    }
    if (index > list->size || index < 1) {
        return false;
    }

    for (int j = index; j < list->size; j++) {
        list->data[j - 1] = list->data[j];
    }

    list->size--;
    if (list->size < list->capacity / 2 - 1) { // Shrink the list
        sl_shrink(list, list->capacity / 2);
    }

    return 1;
}

// Remove the element at the index, return success or not.
static bool sl_delete(SeqList *list, int index, ELEMENT_TYPE *deleted) {
    if (list->size == 0) {
        return false;
    }
    if (index > list->size || index < 1) {
        return false;
    }

    *deleted = list->data[index - 1];
    for (int j = index; j < list->size; j++) {
        list->data[j - 1] = list->data[j];
    }

    list->size--;
    if (list->size < list->capacity / 2 - 1) { // Shrink the list
        sl_shrink(list, list->capacity / 2);
    }
    return 1;
}

// Clear the list, make it empty
static void sl_clear(SeqList *l) {
    l->size = 0;
    free(l->data);
}

// Set the element at the index, return success or not.
static bool sl_set(SeqList *l, int index, int element) {
    if (index > l->size || index < 1) {
        return false;
    }
    l->data[index] = element;
    return true;
}