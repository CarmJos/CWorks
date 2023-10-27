#include <stdio.h>


int main() {

    int score;
    printf("Please input the score: \n");
    scanf("%d", &score);

    if (score < 0 || score > 100) {
        printf("Illegal score.");
        return 0;
    }

    int level = score / 10;
    switch (level) {
        case 10:
        case 9:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
            break;
        default:
            printf("E");
            break;
    }

    return 0;
}
