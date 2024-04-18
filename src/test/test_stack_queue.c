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

//
// Created by Karmu on 2024/4/18.
//

/*
 * 只用两个顺序栈S1,s2(S1、S2的大小分别为Max1、Max2）模拟一个顺序队列时，
 * 不能用到其它的辅助空间。设计用栈的运算实现队列的插入(在可能的条件下，要保证队列元素要能插入成功)、删除以及队列判空运算。
 * 验证示例如下：
 *   1）S1、S2的大小分别为5；S1栈顶用于模拟队列的队尾，S2栈顶用于模拟队列的队头
 *   2）队列分别有5个元素1、2、3、4、5入队，再来5个元素6、7、8、9、10入队，输出当前队列中的所有元素
 *   3）队列出队1个元素，输出当前队列中的所有元素
 *   4）队列再来一个元素11入队
 *   5）队列出队4个元素，输出当前队列中的所有元素
 *   6）队列出队5个元素，再次出队一个元素
 */

#include "../queue/stack_queue.c"

void sq_print(StackQueue *q) {
    printf("S1: [");
    ss_print(q->s1);
    printf("]  ");
    printf("S2: [");
    ss_print(q->s2);
    printf("]");
}

void print_pop(StackQueue *q) {
    int v = sq_dequeue(q);
    if (v < 0) {
        printf("  X Queue is empty\n");
    } else {
        printf("  > Out = %d \n", v);
    }
}

int main() {

    printf("[1] Create a queue (size=5)\n");
    StackQueue *queue = sq_create(5, 5);

    printf("[2] Push 1-5 to queue\n");
    for (int i = 1; i <= 5; i++) {
        if (!sq_enqueue(queue, i)) {
            printf("Queue is full\n");
        }
    }
    printf("  > ");
    sq_print(queue);

    printf("\n  | Then, push 6-10 to queue\n");
    for (int i = 6; i <= 10; i++) {
        if (!sq_enqueue(queue, i)) {
            printf("Queue is full\n");
        }
    }

    printf("  > ");
    sq_print(queue);

    printf("\n[3] Pop an element\n");
    double out = sq_dequeue(queue);
    printf("  > Out = %d \n", (int) out);
    printf("  > ");
    sq_print(queue);

    printf("\n[4] Push 11 to queue\n");
    if (!sq_enqueue(queue, 11)) {
        printf("Queue is full\n");
    }

    printf("[5] Pop 4 elements\n");
    for (int i = 0; i < 4; i++) {
        print_pop(queue);
    }

    printf("  > ");
    sq_print(queue);

    printf("\n[6] Pop 5 elements\n");
    for (int i = 0; i < 4; i++) {
        print_pop(queue);
    }

    printf("  > ");
    sq_print(queue);

    printf("\n");
    printf("  | Pop an element\n");
    print_pop(queue);

    return 0;
}