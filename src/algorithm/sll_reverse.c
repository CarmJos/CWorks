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

// 使用头插法完成单链表的逆置：
// 要求：
// 1）建立两张单链表L1：1 2 3 4 5
// 2）打印单链表L1中的数据
// 3）将L1进行逆置处理
// 4）打印逆置后链表L1中的数据
// 5）将主要的逆置代码以及运行结果截图

void reverse(SingleLinkedList *list) {
    // 头插法翻转链表
    SingleLinkedList *p = list->next;
    list->next = NULL;

    while (p != NULL) {
        SingleLinkedList *temp = p->next;
        p->next = list->next;
        list->next = p;
        p = temp;
    }
}

int main() {
    SingleLinkedList *l1 = sll_create();
    for (int i = 1; i <= 5; i++) {
        sll_add(l1, i);
    }

    printf("before\t->\t");
    sll_print(l1);

    reverse(l1);

    printf("\nafter\t->\t");
    sll_print(l1);
    return 0;
}