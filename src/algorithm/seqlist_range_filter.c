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
#include "../list/sequence_list.h"

// Filter the list by removing elements that are in the range [x, y]
// Return the filtered list, require time complexity O(n), space complexity O(1)
SeqList *filter(SeqList *list, int x, int y) {
    int keep = 0;
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] < x || list->data[i] > y) {
            list->data[keep] = list->data[i];
            keep++;
        }
    }
    list->size = keep;
    return list;
}

int main() {
    SeqList *list = sl_create();
    for (int i = 1; i <= 10; i++) {
        sl_add(list, i);
    }

    SeqList *filtered = filter(list, 1, 5);

    sl_print(filtered);

    return 0;
}