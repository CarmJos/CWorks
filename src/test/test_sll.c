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

#include "../list/single_linked_list.c"
#include "stdio.h"

/*
 *  要求：
 * 1）建立一张单链表，数据为11，12，13，14，15 ；
 * 2）打印单链表中的数据
 * 3）查找第3个数据结点的数据并打印
 * 4）在第5个数据结点后插入数据为16的结点，并打印单链表中的数据
 * 5）删除第1个数据结点，并打印单链表中的数据
 */

int main() {

    printf("1. Create a linked list\n");
    SingleLinkedList *list = sll_create();

    printf("-| Add values to the list\n");
    sll_add(list, 11);
    sll_add(list, 12);
    sll_add(list, 13);
    sll_add(list, 14);
    sll_add(list, 15);
    printf("\n");

    printf("2. Print the list\n");
    printf("-| current -> ");
    sll_print(list);
    printf("\n");

    printf("3. Get the third single_linked_node:\n");
    int third;
    sll_get(list, 3, &third);
    printf("-| The third single_linked_node is %d\n", third);
    printf("\n");

    printf("4. Insert 16 after the fifth single_linked_node\n");
    sll_insert(list, 6, 16);
    printf("-| current -> ");
    sll_print(list);
    printf("\n");

    printf("5. Delete the first single_linked_node\n");
    sll_delete_at(list, 1);
    printf("-| current -> ");
    sll_print(list);
    printf("\n");
}