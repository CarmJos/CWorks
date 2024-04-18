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
// Created by Karmu on 2024/4/18.
//

/*
 * 设计一个支持 push，pop，getmin 等操作
 * 并且可以在 O(1) 时间内检索出最小元素的堆栈A。
 * 验证案例：
 *   1） 创建栈，大小为10，压入元素 3，2，2，1,通过调用getmin打印最小值
 *   2） 弹出1个元素后 通过调用getmin打印最小值
 *   3） 再弹出1个元素后通过调用getmin打印最小值
 *   4） 再次压入元素4，通过调用getmin打印最小值
 */

#include "../stack/min_value_stack.c"

int main() {

    printf("[1] Create a stack (size=10)\n");
    MinValueStack *s = mvs_create(10);
    mvs_push(s, 3);
    mvs_push(s, 2);
    mvs_push(s, 2);
    mvs_push(s, 1);

    printf("[2] Get min value: %d\n", mvs_min(s));

    printf("[3] Pop an element\n");
    mvs_pop(s);
    printf("  | Get min value: %d\n", mvs_min(s));

    printf("[4] Push an element 4\n");
    mvs_push(s, 4);
    printf("  | Get min value: %d\n", mvs_min(s));

}