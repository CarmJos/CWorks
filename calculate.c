#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {

    int a = 7;
    float x = 2.5, y = 4.7;

    printf("%f", x + a % 3 * 7 % 2 / 4);

    return 0;
}
