#include <stdio.h>


// function to connect 2 char array with space without \n
void str_conn(char* str, const char* str1, const char connector) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    int j = 0;
    while (str1[j] != '\0') {
        if (str1[j] != '\n') {
            str[i] = str1[j];
            i++;
        }
        j++;
    }
    str[i] = connector;
}

int main() {
    char str1[50] = {0};
    char str2[50] = {0};

    printf("Input 2 parts of char array: \n");
    fgets(str1, 50,stdin);
    fgets(str2, 50,stdin);

    char str[100] = {0};
    str_conn(str, str1, ' ');
    str_conn(str, str2, ' ');

    printf("Final content ->  %s", str);

    return 0;
}
