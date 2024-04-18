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

//1.利用两个栈sl,s2共用一段顺序存储空间
//2.用栈的运算实现栈的插入，删除，判满以及判空运算
//3.验证如下示例：
//  1）顺序存储空间大小为：5；
//  2）S1分别入栈1，2，3，4，5共5个元素；
//  3）S2入栈元素6，会有栈满提示；
//  4）S1出栈一个元素，S2再次入栈元素6 ；
//  5）打印顺序存储空间中所有元素 ；
//  6）S2连续出栈两次，会有栈空提示


#include "../stack/shared_stack.c"

int main() {

    printf("[1] Create a shared stack (size=5)\n");
    SharedStack *stack = ss_create(5);


    printf("[2] Push 1-5 to left stack;");
    for (int i = 1; i <= 5; i++) {
        ss_push(stack, i, true);
    }

    printf("[3] Push 6 to left stack\n");
    bool success = ss_push(stack, 6, false);
    if (!success) {
        printf("Stack is full\n");
    }

    printf("[4] Pop from left stack and push 6 to right stack\n");
    int out = ss_pop(stack, true);
    printf("Left pop: %d\n", out);
    ss_push(stack, 6, false);

    printf("[5] Print stack\n");
    ss_print(stack);

    printf("[6] Pop 2 elements from right stack\n");
    for (int i = 0; i < 2; i++) {
        out = ss_pop(stack, false);
        if (out < 0) {
            printf("Right stack is empty\n");
            break;
        }
        printf("Right pop: %d\n", out);
    }


}