#include "../list/sequence_list.h"

int main() {
    SeqList *list = sl_create();

    for (int i = 0; i < 20; ++i) {
        sl_insert(list, i, i + 1);
    }

    for (int i = 10; i > 5; i--) {
        int v;
        sl_remove(list, i, &v);
    }

    sl_print(list);
}