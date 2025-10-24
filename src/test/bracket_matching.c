// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2025. CarmJos
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

#include <stdbool.h>
#include "../lib/stack/linked_stack_string.c"

// 使用栈实现前后括号匹配（支持括号、中括号、大括号）
static bool matching(const char* input) {
    LinkedStringStack* stack = s_create(100);
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (c == '(' || c == '[' || c == '{') {
            s_push(stack, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s_empty(stack)) return false;
            char top = s_pop(stack);
            if (c == ')' && top != '(') return false;
            if (c == ']' && top != '[') return false;
            if (c == '}' && top != '{') return false;
        }
    }
    return s_empty(stack);
}

int main() {
    char input[30];
    printf("Please input the values: ");
    gets(input);

    if (matching(input)) {
        printf("Matching!\n");
    }
    else {
        printf("Not matching!\n");
    }

    return 0;
}
