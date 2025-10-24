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

#include "../lib/list/double_linked_list.c"
#include "stdio.h"

/*
 *  要求：
 *  1）建立一张双向链表，数据为1，2，3，4，5 ；
 *  2）打印双向链表中的数据
 *  3）查找第3个数据结点的数据并打印
 *  4）在第5个数据结点后插入数据为6的结点，并打印链表中的数据
 *  5）删除第1个数据结点，并打印链表中的数据
 */

int main() {

    printf("1. Create a linked list\n");
    DoubleLinkedList *list = dll_create();

    printf("-| Add values to the list\n");
    dll_add(list, 1);
    dll_add(list, 2);
    dll_add(list, 3);
    dll_add(list, 4);
    dll_add(list, 5);
    printf("\n");

    printf("2. Print the list\n");
    printf("-| current -> ");
    dll_print(list);
    printf("\n");

    printf("3. Get the third value:\n");
    int third;
    dll_get(list, 3, &third);
    printf("-| The third value is %d\n", third);
    printf("\n");

    printf("4. Insert 6 after the fifth value\n");
    dll_insert(list, 6, 6);
    printf("-| current -> ");
    dll_print(list);
    printf("\n");

    printf("5. Delete the first single_linked_node\n");
    dll_delete_at(list, 1);
    printf("-| current -> ");
    dll_print(list);
    printf("\n");
}