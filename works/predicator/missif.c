#include <stdio.h>

int main() {

    int x;
    scanf("%d", &x);

    int y = -1;

    if (x != 0)
        if (x > 0)
            y = 1;
    else
            y = 0;

    printf("x=%d \ny=%d", x, y);

    return 0;
}
