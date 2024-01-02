#include <stdio.h>

// Insert a number into a array depends on its own order;

int main() {
    int arr[10] = {4, 11, 36, 71, 352, 953};

    int num;
    printf("Please input a number: \n");
    scanf("%d", &num);

    int i = 0;
    while (i < 9 && num > arr[i]) {
        ++i;
    }

    for (int j = 9; j > i; --j) {
        arr[j] = arr[j - 1];
    }

    arr[i] = num;

    for (int j = 0; j < 10; ++j) {
        if (arr[j] != 0)printf("%d ", arr[j]);
    }
    
    return 0;
}
