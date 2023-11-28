// 有一篇文章，三行文字，每行80个字符，统计其中的英文字符大写、英文字符小写、空格、数字和其他字符的个数。

#include <stdio.h>

int count(char *str, char start, char end) {
    int cnt = 0;
    while (*str != '\0') {
        if (*str >= start && *str <= end) {
            cnt++;
        }
        str++;
    }
    return cnt;
}


int main() {
    char article[3][80] = {0};
    printf("Please input 3 lines of article: \n");
    for (int i = 0; i < 3; ++i) {
        fgets(article[i], 80, stdin);
    }

    int upper = 0, lower = 0, space = 0, digit = 0, other = 0;
    for (int i = 0; i < 3; ++i) {
        upper += count(article[i], 'A', 'Z');
        lower += count(article[i], 'a', 'z');
        space += count(article[i], ' ', ' ');
        digit += count(article[i], '0', '9');
        other += count(article[i], '\0', '\377');
    }

    printf("Upper: %d\n", upper);
    printf("Lower: %d\n", lower);
    printf("Space: %d\n", space);
    printf("Digit: %d\n", digit);
    printf("Other: %d\n", other);

    return 0;
}
