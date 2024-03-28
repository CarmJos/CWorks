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
// 1) 在main函数中验证：原始数组为{1，2，3，4，5，6，7，8，9，10}，将其奇偶交换后再将数组中的元素打印出来。结果应该是 {1,3,5,7,9,2,4,6,8,10}
// 2) 将主要的奇偶交换代码以及运行结果截图

int main() {
    SeqList *list = sl_create();
    for (int i = 1; i <= 10; i++) {
        sl_add(list, i);
    }

    int i = 0, j;
    while (i < list->size) {
        if (list->data[i] % 2 == 0) { // 是
            i++;
            continue;
        }

        int temp = list->data[i];
        for (j = i; j > 0; j--) {
            list->data[j] = list->data[j - 1];
        }
        list->data[j] = temp;
        i++;
    }

    sl_print(list);
    return 0;
}