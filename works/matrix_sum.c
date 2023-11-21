#include<stdio.h>

int main() {
    int len;
    printf("Please input the matrix length:\n");
    scanf("%d", &len);

    const int size = len;

    const int matrix[size][size];

    printf("Please input the matrix lines:\n");
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++)
            scanf("%d", &matrix[i][j]);
    }

    // Calc matrix diagonal sum
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += matrix[i][i];

    printf("Sum is %d\n", sum);

    return 0;
}
