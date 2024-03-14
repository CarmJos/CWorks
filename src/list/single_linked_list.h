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

// Linked list (Tail mode)
typedef struct node {
    int data;
    struct node *next;
} LinkedList;

// Create an empty list
static LinkedList *ll_create() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->next = NULL;
    return list;
}

static LinkedList *ll_node(int data, LinkedList *next) {
    LinkedList *node = (LinkedList *) malloc(sizeof(LinkedList));
    node->data = data;
    node->next = next;
    return node;
}

// Add a new node to the list's tail
static void ll_add(LinkedList *l, int data) {
    LinkedList *p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    LinkedList *new_node = ll_node(data, NULL);
    p->next = new_node;
}

// Delete a node from the list
static void ll_delete(LinkedList *l, int data) {
    LinkedList *p = l;
    while (p->next != NULL) {
        if (p->next->data == data) {
            LinkedList *temp = p->next;
            p->next = p->next->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}

// Delete a node from the list by index
static void ll_delete_at(LinkedList *l, int index) {
    LinkedList *p = l;
    int i = 0;
    while (p->next != NULL) {
        i++;
        if (i == index) {
            LinkedList *temp = p->next;
            p->next = p->next->next;
            free(temp);
            return;
        }
        p = p->next;
    }
}

// Print the list
static void ll_print(LinkedList *l) {
    LinkedList *p = l->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Check if the list is empty
static bool ll_empty(LinkedList *l) {
    return l->next == NULL;
}

// Get the first node's data
static int ll_first(LinkedList *l) {
    return l->next->data;
}

// Get the last node's data
static int ll_last(LinkedList *l) {
    LinkedList *p = l;
    while (p->next != NULL) {
        p = p->next;
    }
    return p->data;
}

// Get the index of the target, -1 if not contains
static int ll_index(LinkedList *l, int target) {
    LinkedList *p = l->next;
    int index = 0;
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
static bool ll_contains(LinkedList *l, int target) {
    return ll_index(l, target) != -1;
}

// Get the index of the index to result
static bool ll_get(LinkedList *l, int index, int *result) {
    LinkedList *p = l->next;
    int i = 0;
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
static bool ll_insert(LinkedList *l, int index, int element) {
    LinkedList *p = l;
    int i = 0;
    while (p->next != NULL) {
        i++;
        if (i == index) {
            LinkedList *new_node = ll_node(element, p->next);
            p->next = new_node;
            return true;
        }
        p = p->next;
    }
    LinkedList *new_node = ll_node(element, NULL);
    p->next = new_node;
    return true;
}

// Remove the element from the list
static bool ll_remove(LinkedList *l, int element) {
    LinkedList *p = l;
    while (p->next != NULL) {
        if (p->next->data == element) {
            LinkedList *temp = p->next;
            p->next = p->next->next;
            free(temp);
            return true;
        }
        p = p->next;
    }
    return false;
}