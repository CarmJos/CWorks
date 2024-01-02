#include <stdio.h>

int main() {
    float x, y;
    printf("Please input the point (format: x,y ): \n");
    scanf("%f,%f", &x, &y);

    if ((x - 2) * (x - 2) + (y - 2) * (y - 2) < 1
        || (x - 2) * (x - 2) + (y + 2) * (y + 2) < 1
        || (x + 2) * (x + 2) + (y - 2) * (y - 2) < 1
        || (x + 2) * (x + 2) + (y + 2) * (y + 2) < 1) {
        printf("Height = 10.0\n");
    } else {
        printf("Height = 0.0\n");
    }

    return 0;
}
