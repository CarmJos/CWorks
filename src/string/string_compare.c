#include <stdio.h>

int strcmp(char *str1, char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        i++;
    }
    return str1[i] - str2[i];
}

int main() {
    char str1[50] = {0};
    char str2[50] = {0};

    printf("Input 2 char arrays: \n");
    fgets(str1, 50, stdin);
    fgets(str2, 50, stdin);

    printf("Result ->  %d", strcmp(str1, str2));

    return 0;
}
