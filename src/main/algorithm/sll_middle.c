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

//  使用快慢指针快速找到链表的中间结点;
//要求：
//1）建立两张单链表L1：1 2 3 4 5
//2）打印单链表L1中的数据
//3）打印中间结点的值
//4）将主要的快慢指针查找代码以及运行结果截图

int main() {
    SingleLinkedList *l1 = sll_create();
    for (int i = 1; i <= 5; i++) {
        sll_add(l1, i);
    }

    printf("before\t->\t");
    sll_print(l1);

    SingleLinkedList *fast = l1->next;
    SingleLinkedList *slow = l1->next;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    printf("\nmiddle\t->\t%d", slow->data);

    return 0;
}