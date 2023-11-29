// 有一篇文章，三行文字，每行80个字符，统计其中的英文字符大写、英文字符小写、空格、数字和其他字符的个数。

#include <stdio.h>

static int count(const char* input, const char start, const char end) {
    int i = 0;
    while (*input != '\0') {
        if (*input >= start && *input <= end) {
            i++;
        }
        input++;
    }
    return i;
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
        space += count(article[i], ' ',' ');
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
