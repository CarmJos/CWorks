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

#include <stdio.h>
#include <malloc.h>

#define CAPACITY 10
#define  ELEMENT_TYPE int // 定义数据类型

// 实现循环队列
typedef struct {
    ELEMENT_TYPE *data; // 数据数组
    int front; // 队头指针
    int rear; // 队尾指针
    int size; // 队列的当前大小
} CircleQueue;

CircleQueue *cq_create() {
    CircleQueue *queue = (CircleQueue *) malloc(sizeof(CircleQueue));
    queue->data = (ELEMENT_TYPE *) malloc(CAPACITY * sizeof(int));
    queue->front = queue->rear = 0;
    queue->size = 0;
    return queue;
}

void cq_push(CircleQueue *queue, int data) {
    if (queue->size == CAPACITY) { // 检查是否已满
        printf("Queue is full.\n");
        return;
    }
    queue->data[queue->rear] = data; // 将数据放入队尾
    queue->rear = (queue->rear + 1) % CAPACITY; // 更新队尾指针
    queue->size++; // 更新队列大小
}

int cq_pop(CircleQueue *queue) {
    if (queue->size == 0) { // 检查是否为空
        printf("Queue is empty.\n");
        return -1;
    }
    int data = queue->data[queue->front]; // 取出队头数据
    queue->front = (queue->front + 1) % CAPACITY; // 更新队头指针
    queue->size--; // 更新队列大小
    return data;
}

int cq_empty(CircleQueue *queue) {
    return queue->size == 0; // 判断队列是否为空
}

void cq_clear(CircleQueue *queue) {
    queue->front = queue->rear = 0; // 清空队列
    queue->size = 0; // 更新队列大小
}

void cq_print(CircleQueue *queue) {
    if (cq_empty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d ", queue->data[i]);
        i = (i + 1) % CAPACITY;
    }
    printf("\n");
}




