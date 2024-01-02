#include <stdio.h>

int main() {
    int arr[10][10] = {0};

    for (int i = 0; i < 10; i++) {
        arr[i][0] = 1;
        for (int j = 0; j <= i; j++) {
            if (i == j) arr[i][j] = 1;
            if (i >= 2 && j >= 1) {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            const int num = arr[i][j];
            if (num != 0) printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
