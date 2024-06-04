#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100
typedef struct {
    int top;
    unsigned capacity;
    double *array;
} Stack;

Stack *createStack(unsigned capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (double *) malloc(stack->capacity * sizeof(double));
    if (!stack->array) return NULL;
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, double item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

double pop(Stack *stack) {
    if (isEmpty(stack)) return 0;
    return stack->array[stack->top--];
}

double peek(Stack *stack) {
    if (isEmpty(stack)) return 0;
    return stack->array[stack->top];
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int precedence(char ch) {
    if (ch == '(' || ch == ')') return 0;
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return -1;
}

double applyOp(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            return a / b;
        default:
            return 0;
    }
}

double evaluateExpression(char *expression) {
    Stack *values = createStack(MAX_SIZE);
    Stack *ops = createStack(MAX_SIZE);

    for (int i = 0; expression[i] != '\0'; ++i) {
        char ch = expression[i];

        if (isdigit(ch)) {
            double val = 0;
            while (isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            i--; // Decrement i because for loop will increment it
            push(values, val);
        } else if (ch == '(') {
            push(ops, ch);
        } else if (ch == ')') {
            while (!isEmpty(ops) && peek(ops) != '(') {
                double val2 = pop(values);
                double val1 = pop(values);
                char op = pop(ops);
                push(values, applyOp(val1, val2, op));
            }
            if (!isEmpty(ops) && peek(ops) == '(') {
                pop(ops); // Discard the '('
            } else {
                printf("Invalid expression\n");
                exit(EXIT_FAILURE);
            }
        } else if (isOperator(ch)) {
            while (!isEmpty(ops) && precedence(peek(ops)) >= precedence(ch)) {
                double val2 = pop(values);
                double val1 = pop(values);
                char op = pop(ops);
                push(values, applyOp(val1, val2, op));
            }
            push(ops, ch);
        }
    }

    while (!isEmpty(ops)) {
        double val2 = pop(values);
        double val1 = pop(values);
        char op = pop(ops);
        push(values, applyOp(val1, val2, op));
    }

    double result = pop(values);
    free(values->array);
    free(values);
    free(ops->array);
    free(ops);
    return result;
}

int main() {
    char expression[MAX_SIZE];
    printf("输入您要计算的公式: ");
    fgets(expression, MAX_SIZE, stdin);

    // Remove newline character if present
    expression[strcspn(expression, "\n")] = 0;

    double result = evaluateExpression(expression);
    printf("结果为: %f\n", result);

    return 0;
}

