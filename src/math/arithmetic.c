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

#include "../stack/sequence_stack.c"
#include "../stack/linked_stack_string.c"

// 请编写一个函数，实现一个多位数四则运算计算器
// 要求支持加、减、乘、除四种运算，要求支持括号，要求支持整数和小数的运算。

// 计算优先级
static int priority(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

static char *parse_postfix(const char *expression) {
    LinkedStringStack *operations = s_create(100);
    char *postfix = (char *) malloc(100 * sizeof(char));
    int index = 0;
    for (int i = 0; expression[i] != '\0';) {
        if (expression[i] == ' ') {
            i++;
            continue;
        }
        if (expression[i] == '-' && (i == 0 || expression[i - 1] == '(')) {
            postfix[index++] = '0';  // push 0 to stack
            s_push(operations, '-');  // treat '-' as unary operator
            i++;
        } else if ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
            while ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.') {
                postfix[index++] = expression[i++];
            }
            postfix[index++] = ' ';  // add a space as delimiter
        } else if (expression[i] == '(') {
            s_push(operations, '(');
            i++;
        } else if (expression[i] == ')') {
            while (s_top(operations) != '(') {
                postfix[index++] = s_pop(operations);
            }
            s_pop(operations);
            i++;
        } else {
            while (!s_empty(operations) && priority(s_top(operations)) >= priority(expression[i])) {
                postfix[index++] = s_pop(operations);
            }
            s_push(operations, expression[i]);
            i++;
        }
    }
    while (!s_empty(operations)) {
        postfix[index++] = s_pop(operations);
    }
    postfix[index] = '\0';
    return postfix;
}


static double simple_calc(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

static double calculate(const char *expression) {
    char *postfix = parse_postfix(expression);
    SeqStack *stack = ss_create(100);
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            double num = 0;
            while (postfix[i] >= '0' && postfix[i] <= '9') {
                num = num * 10 + (postfix[i++] - '0');
            } // 支持多位数
            ss_push(stack, num);
        } else if (postfix[i] != ' ') {
            double a = ss_pop(stack);
            double b = ss_pop(stack);
            ss_push(stack, simple_calc(a, b, postfix[i]));
        }
    }
    free(postfix);
    return ss_pop(stack);
}