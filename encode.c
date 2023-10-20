#include <stdio.h>

#define OFFSET 4

char offset(char input) {
    return (char) (input + OFFSET);
}

int main() {
    printf("Please input the code that want to offset:\n");
    
    char c1 = getchar();
    char c2 = getchar();
    char c3 = getchar();
    char c4 = getchar();
    char c5 = getchar();

    putchar(offset(c1));
    putchar(offset(c2));
    putchar(offset(c3));
    putchar(offset(c4));
    putchar(offset(c5));
    printf("\n");

    printf("%c%c%c%c%c", offset(c1), offset(c2), offset(c3), offset(c4), offset(c5));

    return 0;
}
