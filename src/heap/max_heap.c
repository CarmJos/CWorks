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
#include <stdbool.h>

#define ELEMENT_TYPE int
#define MAX_HEAP_CAPACITY 100

// 实现最大完全二叉堆

typedef struct max_heap_node {
    ELEMENT_TYPE *data; // 数据数组
    int size; // 堆的当前大小
} MaxHeap;

MaxHeap *mh_create() {
    MaxHeap *heap = (MaxHeap *) malloc(sizeof(MaxHeap));
    heap->data = (ELEMENT_TYPE *) malloc(MAX_HEAP_CAPACITY * sizeof(ELEMENT_TYPE));
    heap->size = 0;
    return heap;
}

// 堆化数据
void mh_heapify(MaxHeap *heap, int i) {
    ELEMENT_TYPE data = heap->data[i];
    int child;
    while (i * 2 <= heap->size) {
        child = i * 2;
        if (child != heap->size && heap->data[child] < heap->data[child + 1]) {
            child++;
        }
        if (data >= heap->data[child]) {
            break;
        }
        heap->data[i] = heap->data[child];
        i = child;
    }
    heap->data[i] = data;
}

// offer插入数据，同时利用 heapify 上浮操作建堆
void mh_offer(MaxHeap *heap, ELEMENT_TYPE data) {
    if (heap->size == MAX_HEAP_CAPACITY) {
        printf("Heap is full.\n");
        return;
    }
    heap->data[++heap->size] = data;
    int i = heap->size;
    while (i != 1 && data > heap->data[i / 2]) {
        heap->data[i] = heap->data[i / 2];
        i /= 2;
    }
    heap->data[i] = data;
}

// 提取的同时 利用 heapify 建堆
ELEMENT_TYPE mh_poll(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }
    ELEMENT_TYPE data = heap->data[1];
    heap->data[1] = heap->data[heap->size--];
    mh_heapify(heap, 1);
    return data;
}

ELEMENT_TYPE mh_peek(MaxHeap *heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return -1;
    }
    return heap->data[1];
}

bool mh_empty(MaxHeap *heap) {
    return heap->size == 0;
}

void mh_clear(MaxHeap *heap) {
    heap->size = 0;
}

void mh_print(MaxHeap *heap) {
    if (mh_empty(heap)) {
        printf("Heap is empty.\n");
        return;
    }
    for (int i = 1; i <= heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

