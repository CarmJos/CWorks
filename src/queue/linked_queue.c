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

#define  ELEMENT_TYPE int // 定义数据类型

// 实现链式队列
typedef struct queue_node {
    ELEMENT_TYPE data;
    struct queue_node *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} LinkedQueue;

LinkedQueue *lq_create() {
    LinkedQueue *queue = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    queue->front = queue->rear = (QueueNode *) malloc(sizeof(QueueNode));
    queue->front->next = NULL;
    return queue;
}

void lq_enqueue(LinkedQueue *queue, ELEMENT_TYPE data) {
    QueueNode *new_node = (QueueNode *) malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;
    queue->rear->next = new_node;
    queue->rear = new_node;
}

ELEMENT_TYPE lq_dequeue(LinkedQueue *queue) {
    if (queue->front->next == NULL) {
        return -1;
    }
    QueueNode *temp = queue->front->next;
    ELEMENT_TYPE data = temp->data;
    queue->front->next = temp->next;
    if (queue->rear == temp) {
        queue->rear = queue->front;
    }
    free(temp);
    return data;
}

ELEMENT_TYPE lq_empty(LinkedQueue *queue) {
    return queue->front->next == NULL;
}

void lq_clear(LinkedQueue *queue) {
    while (queue->front->next != NULL) {
        QueueNode *temp = queue->front->next;
        queue->front->next = temp->next;
        free(temp);
    }
    queue->rear = queue->front;
}

void lq_prELEMENT(LinkedQueue *queue) {
    QueueNode *p = queue->front->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
