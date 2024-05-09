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
#include <stdlib.h> // 使用stdlib.h替换malloc.h，因为stdlib包含了malloc的定义

// 定义数据类型
#define ELEMENT_TYPE void* // 使用void* 来存储任意类型的数据

// 实现链式队列
typedef struct queue_node {
    ELEMENT_TYPE data;
    struct queue_node *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} LinkedQueue;

// 创建队列
LinkedQueue *lq_create() {
    LinkedQueue *queue = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    queue->front = queue->rear = (QueueNode *) malloc(sizeof(QueueNode));
    queue->front->next = NULL;
    return queue;
}

// 入队操作
void lq_enqueue(LinkedQueue *queue, ELEMENT_TYPE data) {
    QueueNode *new_node = (QueueNode *) malloc(sizeof(QueueNode));
    new_node->data = data;
    new_node->next = NULL;
    queue->rear->next = new_node;
    queue->rear = new_node;
}

// 出队操作
ELEMENT_TYPE lq_dequeue(LinkedQueue *queue) {
    if (queue->front->next == NULL) {
        return NULL; // 适应 void* 类型，返回NULL代表队列为空
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

// 判断队列是否为空
int lq_empty(LinkedQueue *queue) {
    return queue->front->next == NULL;
}

// 清空队列
void lq_clear(LinkedQueue *queue) {
    while (!lq_empty(queue)) {
        lq_dequeue(queue);
    }
}

// 打印队列元素
void lq_print(LinkedQueue *queue) {
    QueueNode *p = queue->front->next;
    while (p != NULL) {
        printf("%p ", p->data); // 打印指针的值
        p = p->next;
    }
}
