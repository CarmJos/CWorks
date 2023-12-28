#include <stdio.h>

static int calc(const int a, const int b) {
    return b == 0 || a == b ? 1 : calc(a - 1, b) + calc(a - 1, b - 1);
}

int main() {
    int n = 0;
    printf("Please input the line that want to display: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", calc(i, j));
        }
        printf("\n");
    }

    return 0;
}
