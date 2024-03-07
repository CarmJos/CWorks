#include "../list/sequence_list.h"

int main() {
    SeqList *list = sl_create();

    int total;
    printf("Please input total monkeys(1~50): ");
    scanf("%d", &total);

    for (int i = 0; i < total; ++i) {
        sl_add(list, i + 1); // Put monkeys
    }

    int cycle;
    printf("Please input the cycle numbers (>1): ");
    scanf("%d", &cycle);

    int count = 0;
    int position = 0;
    while (list->size > 1) {
        if (count == cycle) {
            int removed;
            sl_delete(list, position, &removed);
            printf("Removed @%d -> %d\n", position, removed);
            printf("Current: ");
            sl_print(list);
            printf("\n");
            count = 0; // reset for next round
            position--;
        } else {
            count++;
            if (position >= list->size) {
                position = 1;
            } else {
                position++;
            }
        }
    }
    sl_print(list);
    return 0;
}