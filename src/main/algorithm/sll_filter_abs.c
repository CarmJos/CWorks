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
// Created by Karmu on 2024/3/28.
//

#include "../list/single_linked_list.h"
#include "../list/sequence_list.h"

//  删除单链表中绝对值相同的节点：
//要求：
//1）建立一张单链表，数据为 21 -15 -15 -7 15；
//2）打印单链表中的数据
//3）进行删除操作：对于链表中绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。
//4）打印单删除后链表中的数据
//5）将主要的删除代码以及运行结果截图

static SingleLinkedList *purge_abs_duplicate(SingleLinkedList *list) {
    SeqList *exists = sl_create();

    SingleLinkedList *p = list->next;
    SingleLinkedList *prev = list;
    while (p != NULL) {
        if (sl_contains(exists, abs(p->data))) {
            prev->next = p->next; // 指向下一个节点
            p = prev->next;
        } else {
            sl_add(exists, abs(p->data));
            prev = p;
            p = p->next;
        }
    }
    return list;
}

int main() {
    SingleLinkedList *l1 = sll_create();
    sll_add(l1, 21);
    sll_add(l1, -15);
    sll_add(l1, -15);
    sll_add(l1, -7);
    sll_add(l1, 15);

    printf("before\t->\t");
    sll_print(l1);

    purge_abs_duplicate(l1);

    printf("\nafter\t->\t");
    sll_print(l1);
    return 0;
}