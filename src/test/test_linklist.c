#include "../list/linked_list.h"
#include "stdio.h"

int main() {

    int size;
    printf("Please input the size of the linked list:\n");
    scanf("%d", &size);

    LinkedList *head = ll_create();
    int value;
    for (int i = 0; i < size; ++i) {
        printf("Please input the value of the %dth node:\n", i + 1);
        scanf("%d", &value);
        ll_add(head, value);
    }

    printf("The linked list is: ");
    ll_print(head);

}