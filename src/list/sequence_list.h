#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"

#define INITIATE_SIZE 10

typedef struct {
    int *data;
    int size;
    int capacity;
} SeqList;

// Create an empty list
SeqList *sl_create() {
    SeqList *list = (SeqList *) malloc(sizeof(SeqList));
    list->data = (int *) malloc(INITIATE_SIZE * sizeof(int));
    list->size = 0;
    list->capacity = INITIATE_SIZE;
    return list;
}

// Expand the list's capacity
void sl_expand(SeqList *l) {
    int *new_data = (int *) malloc(l->capacity * 2 * sizeof(int));
    for (int i = 0; i < l->size; i++) {
        new_data[i] = l->data[i];
    }
    free(l->data);
    l->data = new_data;
    l->capacity *= 2;
}

// Shrink the list's capacity
void sl_shrink(SeqList *l, int amount) {
    int after = l->capacity - amount;
    int *new_data = (int *) malloc(after * sizeof(int));
    l->size = l->size > after ? after : l->size;
    for (int i = 0; i < l->size; i++) {
        new_data[i] = l->data[i];
    }
    free(l->data);
    l->data = new_data;
    l->capacity = after;
}

// Put the whole array into the list, return success or not.
bool sl_put(SeqList *l, const int *array, int length) {
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
bool sl_empty(SeqList *l) {
    return l->size == 0;
}

// Out print the whole list
void sl_print(SeqList *l) {
    for (int i = 0; i < l->size; i++)
        printf("%d ", (l->data[i]));
}

// Get the index of the target, -1 if not contains
int sl_index(SeqList *l, int target) {
    for (int i = 0; i < l->size; i++) {
        if (l->data[i] == target) {
            return i + 1;
        }
    }
    return -1;
}

// Check if the target contains in the list, return success or not.
bool sl_contains(SeqList *l, int target) {
    for (int i = 0; i < l->size; i++) {
        if (l->data[i] == target) {
            return true;
        }
    }
    return false;
}

// Get the index of the index to result, return success or not.
bool sl_get(SeqList *list, int index, int *result) {
    if (index < 1 || index > list->size) {
        return false;
    } else {
        *result = list->data[index];
        return true;
    }
}

// Add the element to the list, return success or not.
bool sl_add(SeqList *list, int element) {
    if (list->size >= list->capacity) {
        sl_expand(list);
    }

    list->data[list->size] = element;
    list->size++;

    return true;
}

// Insert the element into the target index, return success or not.
bool sl_insert(SeqList *list, int index, int element) {
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
bool sl_remove(SeqList *list, int index) {
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
bool sl_delete(SeqList *list, int index, int *deleted) {
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
void sl_clear(SeqList *l) {
    l->size = 0;
    free(l->data);
}

// Set the element at the index, return success or not.
bool sl_set(SeqList *l, int index, int element) {
    if (index > l->size || index < 1) {
        return false;
    }
    l->data[index] = element;
    return true;
}