#include <stdio.h>

int main() {

    double height = 100;
    double sum = 0;

    for (int i = 0; i < 10; ++i) {
        sum += height * (i > 0 ? 2 : 1);
        height /= 2;
        printf(
                "#%d -> sum=%.2lf / rebound=%.2lf  \n",
                i + 1, sum, height
        );
    }
}
