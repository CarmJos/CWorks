#include <stdio.h>
#define OFFSET 4

char offset(char input) {
    return (char) (input + OFFSET);
}

int main() {

    char c1 = 'C', c2 = 'h', c3 = 'i', c4 = 'n', c5 = 'a';

    putchar(offset(c1));
    putchar(offset(c2));
    putchar(offset(c3));
    putchar(offset(c4));
    putchar(offset(c5));
    printf("\n");

    printf("%c%c%c%c%c", offset(c1), offset(c2), offset(c3), offset(c4), offset(c5));

    return 0;
}
