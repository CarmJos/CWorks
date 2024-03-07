#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"

#define MAXSIZE 50

typedef struct {
    int data[MAXSIZE];
    int last;
} SeqList;

// Create a empty list
SeqList *SeqList_create() {
    SeqList *list;
    list = malloc(sizeof(SeqList));
    list->last = 0;
    return list;
}

// Put the whole array into the list, return success or not.
bool SeqList_put(SeqList *l, const int *array, int length) {
    if (length > MAXSIZE) {
        return false;
    }
    for (int k = 0; k < length; k++) {
        l->data[k] = array[k];
    }
    l->last = length;
    return 1;
}

// Check if the list is empty, return success or not.
bool SeqList_empty(SeqList *l) {
    if (l->last == 0)
        return true;
    else
        return false;
}

// Out print the whole list
void SeqList_print(SeqList *l) {
    for (int i = 0; i < l->last; i++)
        printf("%d ", (l->data[i]));
}

// Get the index of the target, -1 if not contains
int SeqList_index(SeqList *l, int target) {
    for (int i = 0; i < l->last; i++) {
        if (l->data[i] == target) {
            return i + 1;
        }
    }
    return -1;
}

// Check if the target contains in the list, return success or not.
bool SeqList_contains(SeqList *l, int target) {
    for (int i = 0; i < l->last; i++) {
        if (l->data[i] == target) {
            return true;
        }
    }
    return false;
}

// Get the index of the index to result, return success or not.
bool SeqList_get(SeqList *list, int index, int *result) {
    if (index < 1 || index > list->last) {
        return false;
    } else {
        *result = list->data[index];
        return true;
    }
}

// Insert the element into the target index, return success or not.
bool SeqList_insert(SeqList *list, int index, int element) {
    if (list->last >= MAXSIZE) {
        return false; // Full
    }

    if (index < 1 || index > list->last) {
        return false; // Wrong index
    }

    for (int k = list->last; k > index; k--) {
        list->data[k] = list->data[k - 1];
    }

    list->data[index] = element;
    list->last++;

    return true;
}

// Remove the element at the index, return success or not.
bool SeqList_remove(SeqList *list, int index, int *deleted) {
    if (list->last == 0) {
        return false;
    }
    if (index > list->last || index < 1) {
        return false;
    }

    *deleted = list->data[index - 1];
    for (int j = index; j < list->last; j++) {
        list->data[j - 1] = list->data[j];
    }
    list->last--;
    return 1;
}

// Clear the list, make it empty
void SeqList_clear(SeqList *l) {
    l->last = 0;
}

// Set the element at the index, return success or not.
bool SeqList_set(SeqList *l, int index, int element) {
    if (index > l->last || index < 1) {
        return false;
    }
    l->data[index] = element;
    return true;
}