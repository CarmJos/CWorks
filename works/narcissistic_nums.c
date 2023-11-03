#include<stdio.h>


int cube(int v) {
    return v * v * v;
}

int calc(int v) {
    return (cube(v % 10) + cube(v / 10 % 10) + cube(v / 100 % 10));
}

int main() {
    int i = 100;

    while (i < 1000) {
        if (i == calc(i)) {
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}

