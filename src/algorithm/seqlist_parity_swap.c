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

// 将所在奇数移到所有偶数的前面，要求算法的时间复杂度为O(n)，空间复杂度为O(1)。
// 要求：
// 1) 在main函数中验证：原始数组为{1，2，3，4，5，6，7，8，9，10}，将其奇偶交换后再将数组中的元素打印出来
// 2) 将主要的奇偶交换代码以及运行结果截图

static void swap(SeqList *list, int i, int j) {
    int temp = list->data[i];
    list->data[i] = list->data[j];
    list->data[j] = temp;
}

int main() {
    SeqList *list = sl_create();
    for (int i = 1; i <= 10; i++) {
        sl_add(list, i);
    }

    printf("before\t->\t");
    sl_print(list);
    printf("\n");

    int i = 0, j = list->size - 1;
    while (i < j) {
        while (list->data[i] % 2 != 0) {
            i++;
        }
        while (list->data[j] % 2 == 0) {
            j--;
        }
        if (i < j) swap(list, i, j);
    }

    printf("after\t->\t");
    sl_print(list);
    return 0;
}