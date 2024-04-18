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

#include "../list/sequence_list.c"

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