#include <stdio.h>

struct Point {
    double x;
    double y;
};
struct Circle {
    struct Point center;
    double radius;
};

// calculate the squared distance of two points
double distanceSquare(struct Point p1, struct Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// predicate the point(x, y) whether inside the circle(circleX, circleY, circleRadius)
int isInside(struct Point point, struct Circle circle) {
    return distanceSquare(point, circle.center) < circle.radius * circle.radius;
}

int main() {
    float x, y;
    printf("Please input the point (format: x,y ): \n");
    scanf("%f,%f", &x, &y);

    struct Point point = {x, y};
    struct Circle circle1 = {{2, 2}, 1};
    struct Circle circle2 = {{2, -2}, 1};
    struct Circle circle3 = {{-2, 2}, 1};
    struct Circle circle4 = {{-2, -2}, 1};

    if (isInside(point, circle1) || isInside(point, circle2)
        || isInside(point, circle3) || isInside(point, circle4)) {
        printf("Height = 10.0\n");
    } else {
        printf("Height = 0.0\n");
    }
    return 0;
}



