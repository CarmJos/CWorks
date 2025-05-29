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

/**
* 只用两个顺序栈s1,s2(S1、S2的大小分别为Max1、Max2）模拟一个顺序队列时，不能用到其它的辅助空间。
* 设计用栈的运算实现队列的插入(在可能的条件下，要保证队列元素要能插入成功)、删除以及队列判空运算。
*/

#include "../stack/sequence_stack.c"

typedef struct {
    SeqStack *s1;
    SeqStack *s2;
} StackQueue;

StackQueue *sq_create(int max1, int max2) {
    StackQueue *ds = (StackQueue *) malloc(sizeof(StackQueue));
    ds->s1 = ss_create(max1);
    ds->s2 = ss_create(max2);
    return ds;
}

bool sq_empty(StackQueue *q) {
    return ss_empty(q->s1) && ss_empty(q->s2);
}

bool sq_full(StackQueue *q) {
    return ss_full(q->s1) && ss_full(q->s2);
}

bool sq_enqueue(StackQueue *q, ELEMENT_TYPE c) {
    // 将元素压入 S1,如果 S1 满了，而 S2 为空，则将 S1 中的所有元素转移到 S2 中，然后继续压入新元素到 S1。
    if (ss_full(q->s1) && ss_empty(q->s2)) {
        while (!ss_empty(q->s1)) {
            ss_push(q->s2, ss_pop(q->s1));
        }
    }
    if (ss_full(q->s1) && ss_full(q->s2)) {
        return false;
    }
    ss_push(q->s1, c);
    return true;
}

ELEMENT_TYPE sq_dequeue(StackQueue *q) {
    // 将 S2 中的元素出栈，如果 S2 为空，则将 S1 中的所有元素转移到 S2 中，然后再出栈。
    if (ss_empty(q->s2)) {
        while (!ss_empty(q->s1)) {
            ss_push(q->s2, ss_pop(q->s1));
        }
    }
    return ss_pop(q->s2);
}
