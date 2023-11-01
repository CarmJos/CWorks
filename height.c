#include <stdio.h>

double distanceSquare(double x, double y, double a, double b) {
    return (x - a) * (x - a) + (y - b) * (y - b);
}

int insideCircle(double x, double y, double circleX, double circleY, double circleRadius) {
    return distanceSquare(x, y, circleX, circleY) < circleRadius * circleRadius;
}

int main() {

    float x, y;
    printf("Please input the point (format: x,y ): \n");
    scanf("%f,%f", &x, &y);

    if (insideCircle(x, y, 2, 2, 1)
        || insideCircle(x, y, 2, -2, 1)
        || insideCircle(x, y, -2, 2, 1)
        || insideCircle(x, y, -2, -2, 1))
        printf("Height = 10.0\n");
    else
        printf("Height = 0.0\n");

    return 0;
}
