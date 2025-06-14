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

// 双向链表的实现，支持增删改查等操作。
#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"

#define ELEMENT_TYPE int // 定义数据类型

typedef struct double_linked_node {
    ELEMENT_TYPE data;
    struct double_linked_node* prev;
    struct double_linked_node* next;
} DoubleLinkedList;

static DoubleLinkedList* dll_node(ELEMENT_TYPE data, DoubleLinkedList* prev, DoubleLinkedList* next) {
    DoubleLinkedList* node = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    node->data = data;
    node->prev = prev;
    node->next = next;
    return node;
}

// Create an empty list
static DoubleLinkedList* dll_create() {
    return dll_node(0, NULL, NULL);
}

// Add a new queue_node to the list's tail
static void dll_add(DoubleLinkedList* l, ELEMENT_TYPE data) {
    DoubleLinkedList* p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    DoubleLinkedList* new_node = dll_node(data, p, NULL);
    p->next = new_node;
}

// Delete a queue_node from the list
static void dll_delete(DoubleLinkedList* l, ELEMENT_TYPE data) {
    DoubleLinkedList* p = l;
    while (p->next != NULL) {
        if (p->next->data == data) {
            DoubleLinkedList* temp = p->next;
            p->next = p->next->next;
            if (p->next != NULL) {
                p->next->prev = p;
            }
            free(temp);
            return;
        }
        p = p->next;
    }
}

// Delete a queue_node from the list by index
static void dll_delete_at(DoubleLinkedList* l, ELEMENT_TYPE index) {
    DoubleLinkedList* p = l;
    ELEMENT_TYPE i = 0;
    while (p->next != NULL) {
        if (i == index) {
            DoubleLinkedList* temp = p->next;
            p->next = p->next->next;
            if (p->next != NULL) {
                p->next->prev = p;
            }
            free(temp);
            return;
        }
        p = p->next;
        i++;
    }
}

// PrELEMENT the list
static void dll_print(DoubleLinkedList* l) {
    DoubleLinkedList* p = l->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Get the index of the target, -1 if not contains
static ELEMENT_TYPE dll_index(DoubleLinkedList* l, ELEMENT_TYPE target) {
    ELEMENT_TYPE i = 0;
    DoubleLinkedList* p = l->next;
    while (p != NULL) {
        if (p->data == target) {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}

// Check if the list is empty
static bool dll_empty(DoubleLinkedList* l) {
    return l->next == NULL;
}

// Get the first queue_node's data
static ELEMENT_TYPE dll_first(DoubleLinkedList* l) {
    return l->next->data;
}

// Get the last queue_node's data
static ELEMENT_TYPE dll_last(DoubleLinkedList* l) {
    DoubleLinkedList* p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    return p->data;
}

// Get the index of the target, -1 if not contains
static bool dll_contains(DoubleLinkedList* l, ELEMENT_TYPE target) {
    return dll_index(l, target) != -1;
}

// Get the index of the index to result, return success or not.
static bool dll_get(DoubleLinkedList* list, ELEMENT_TYPE index, ELEMENT_TYPE* result) {
    ELEMENT_TYPE i = 0;
    DoubleLinkedList* p = list->next;
    while (p != NULL) {
        if (i == index - 1) {
            *result = p->data;
            return true;
        }
        p = p->next;
        i++;
    }
    return false;
}

// Insert the element ELEMENTo the target index.
static void dll_insert(DoubleLinkedList* list, ELEMENT_TYPE index, ELEMENT_TYPE element) {
    ELEMENT_TYPE i = 0;
    DoubleLinkedList* p = list;
    while (p->next != NULL) {
        if (i == index) {
            DoubleLinkedList* new_node = dll_node(element, p, p->next);
            p->next->prev = new_node;
            p->next = new_node;
            return;
        }
        p = p->next;
        i++;
    }
    DoubleLinkedList* new_node = dll_node(element, p, NULL);
    p->next = new_node;
}

// Get the size of the list
static ELEMENT_TYPE dll_size(DoubleLinkedList* l) {
    ELEMENT_TYPE size = 0;
    DoubleLinkedList* p = l->next;
    while (p != NULL) {
        size++;
        p = p->next;
    }
    return size;
}

// Clear the list
static void dll_clear(DoubleLinkedList* l) {
    DoubleLinkedList* p = l->next;
    while (p != NULL) {
        DoubleLinkedList* temp = p;
        p = p->next;
        free(temp);
    }
    l->next = NULL;
}

// Destroy the list
static void dll_destroy(DoubleLinkedList* l) {
    dll_clear(l);
    free(l);
}
