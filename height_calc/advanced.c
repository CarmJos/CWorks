#include <stdio.h> // Import the standard input and output library.
#include "area.h" // Import the header file about area calculation.

int main() {
    float x, y;
    printf("Please input the point (format: x,y ): \n");
    scanf("%f,%f", &x, &y);

    Point point = {x, y};
    Circle circle1 = {{2, 2}, 1};
    Circle circle2 = {{2, -2}, 1};
    Circle circle3 = {{-2, 2}, 1};
    Circle circle4 = {{-2, -2}, 1};

    if (isInside(point, circle1) || isInside(point, circle2)
        || isInside(point, circle3) || isInside(point, circle4)) {
        printf("Height = 10.0\n");
    } else {
        printf("Height = 0.0\n");
    }

    return 0;
}



