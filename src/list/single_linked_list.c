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

// 单向链表的实现，支持增删改查等操作。
#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"

#define  ELEMENT_TYPE int // 定义数据类型

// Linked list (Tail mode)
typedef struct single_linked_node {
    ELEMENT_TYPE data;
    struct single_linked_node *next;
} SingleLinkedList;

static SingleLinkedList *sll_node(ELEMENT_TYPE data, SingleLinkedList *next) {
    SingleLinkedList *node = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));
    node->data = data;
    node->next = next;
    return node;
}

// Create an empty list
static SingleLinkedList *sll_create() {
    return sll_node(0, NULL);
}

static void sll_link(SingleLinkedList *l, SingleLinkedList *node) {
    SingleLinkedList *p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;
}

// Add a new single_linked_node to the list's tail
static void sll_add(SingleLinkedList *l, ELEMENT_TYPE data) {
    sll_link(l, sll_node(data, NULL));
}


// Delete a single_linked_node from the list
static void sll_delete(SingleLinkedList *l, ELEMENT_TYPE data) {
    SingleLinkedList *p = l;
    while (p->next != NULL) {
        if (p->next->data == data) {
            SingleLinkedList *temp = p->next;
            p->next = p->next->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}

// Delete a single_linked_node from the list by index
static void sll_delete_at(SingleLinkedList *l, ELEMENT_TYPE index) {
    SingleLinkedList *p = l;
    ELEMENT_TYPE i = 0;
    while (p->next != NULL) {
        i++;
        if (i == index) {
            SingleLinkedList *temp = p->next;
            p->next = p->next->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}

// PrELEMENT the list
static void sll_print(SingleLinkedList *l) {
    SingleLinkedList *p = l->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Check if the list is empty
static bool sll_empty(SingleLinkedList *l) {
    return l->next == NULL;
}

// Get the first single_linked_node's data
static ELEMENT_TYPE sll_first(SingleLinkedList *l) {
    return l->next->data;
}

// Get the last single_linked_node's data
static ELEMENT_TYPE sll_last(SingleLinkedList *l) {
    SingleLinkedList *p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    return p->data;
}

// Get the index of the target, -1 if not contains
static ELEMENT_TYPE sll_index(SingleLinkedList *l, ELEMENT_TYPE target) {
    SingleLinkedList *p = l->next;
    ELEMENT_TYPE index = 0;
    while (p != NULL) {
        index++;
        if (p->data == target) {
            return index;
        }
        p = p->next;
    }
    return -1;
}

// Check if the target contains in the list
static bool sll_contains(SingleLinkedList *l, ELEMENT_TYPE target) {
    return sll_index(l, target) != -1;
}

// Get the index of the index to result
static bool sll_get(SingleLinkedList *l, ELEMENT_TYPE index, ELEMENT_TYPE *result) {
    SingleLinkedList *p = l->next;
    ELEMENT_TYPE i = 0;
    while (p != NULL) {
        i++;
        if (i == index) {
            *result = p->data;
            return true;
        }
        p = p->next;
    }
    return false;
}

// Insert the element after the target index, if the index is out of range, insert to the tail
static bool sll_insert(SingleLinkedList *l, ELEMENT_TYPE index, ELEMENT_TYPE element) {
    SingleLinkedList *p = l;
    ELEMENT_TYPE i = 0;
    while (p->next != NULL) {
        i++;
        if (i == index) {
            SingleLinkedList *new_node = sll_node(element, p->next);
            p->next = new_node;
            return true;
        }
        p = p->next;
    }
    SingleLinkedList *new_node = sll_node(element, NULL);
    p->next = new_node;
    return true;
}

// Remove the element from the list
static bool sll_remove(SingleLinkedList *l, ELEMENT_TYPE element) {
    SingleLinkedList *p = l;
    while (p->next != NULL) {
        if (p->next->data == element) {
            SingleLinkedList *temp = p->next;
            p->next = p->next->next;
            free(temp);
            return true;
        }
        p = p->next;
    }
    return false;
}

// Get the size of the list
static ELEMENT_TYPE sll_size(SingleLinkedList *l) {
    ELEMENT_TYPE size = 0;
    SingleLinkedList *p = l->next;
    while (p != NULL) {
        size++;
        p = p->next;
    }
    return size;
}

// Clear the list
static void sll_clear(SingleLinkedList *l) {
    SingleLinkedList *p = l->next;
    while (p != NULL) {
        SingleLinkedList *temp = p;
        p = p->next;
        free(temp);
    }
    l->next = NULL;
}

// Destroy the list
static void sll_destroy(SingleLinkedList *l) {
    sll_clear(l);
    free(l);
}
