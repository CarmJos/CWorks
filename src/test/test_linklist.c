#include "../list/linked_list.h"
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
    LinkedList *list = ll_create();

    printf("-| Add values to the list\n");
    ll_add(list, 11);
    ll_add(list, 12);
    ll_add(list, 13);
    ll_add(list, 14);
    ll_add(list, 15);
    printf("\n");

    printf("2. Print the list\n");
    printf("-| current -> ");
    ll_print(list);
    printf("\n");

    printf("3. Get the third node:\n");
    int third;
    ll_get(list, 3, &third);
    printf("-| The third node is %d\n", third);
    printf("\n");

    printf("4. Insert 16 after the fifth node\n");
    ll_insert(list, 6, 16);
    printf("-| current -> ");
    ll_print(list);
    printf("\n");

    printf("5. Delete the first node\n");
    ll_delete_at(list, 1);
    printf("-| current -> ");
    ll_print(list);
    printf("\n");
}