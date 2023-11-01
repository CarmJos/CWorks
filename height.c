#include <stdio.h>

// calculate the squared distance of two points
double distanceSquare(double x, double y, double a, double b) {
    return (x - a) * (x - a) + (y - b) * (y - b);
}

// predicate the point(x, y) whether inside the circle(circleX, circleY, circleRadius)
int insideCircle(double pointX, double pointY,
                 double circleX, double circleY, double circleRadius) {
    return distanceSquare(pointX, pointY, circleX, circleY) < circleRadius * circleRadius;
}

int main() {

    float x, y;
    printf("Please input the point (format: x,y ): \n");
    scanf("%f,%f", &x, &y);

    if (insideCircle(x, y, 2, 2, 1)
        || insideCircle(x, y, 2, -2, 1)
        || insideCircle(x, y, -2, 2, 1)
        || insideCircle(x, y, -2, -2, 1)) {
        printf("Height = 10.0\n");
    } else {
        printf("Height = 0.0\n");
    }


    return 0;
}



