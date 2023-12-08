#include <stdio.h>
#include <math.h>

int int_ascii(int n, char *str, int i) {
    if (n == 0) return i;
    str[i] = (n % 10) + '0';
    return int_ascii(n / 10, str, i + 1);
}

char *covert(int num, char *str) {
    int len = int_ascii(abs(num), str, 0);

    if (num < 0) {
        str[len] = '-';
        len++;
    }

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }

    return str;
}

int main() {
    int num;
    printf("Please input the number: \n");
    scanf("%d", &num);

    char str[21] = {0};
    printf("Result -> %s\n", covert(num, str));
    return 0;
}

