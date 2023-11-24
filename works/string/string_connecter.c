#include <stdio.h>


// function to connect 2 char array with space
void str_conn(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0') {
        i++;
    }
    str1[i] = ' ';
    i++;
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
}

int main() {
    char str1[20] = {0};
    char str2[20] = {0};

    printf("Input 2 parts of char array: \n");
    scanf("%s %s", str1, str2);
    str_conn(str1, str2);

    printf("Final content ->  %s", str1);

    return 0;
}
