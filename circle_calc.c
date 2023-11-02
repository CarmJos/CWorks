#include <stdio.h>
#include <math.h>

#define PI 3.1415926

int main() {

    float r, h;
    printf("Type the circle radius and height of the cylinder (format r,h): \n");
    scanf("%f,%f", &r, &h);


    printf("Bottom perimeter = %.2lf\n", r * 2 * PI);

    float bottomArea = r * r * PI;
    printf("Bottom area = %.2lf\n", bottomArea);

    float ballRadius = sqrtf((r * r) + (h * h / 4));
    printf("Surface area of the outer ball = %.2lf\n", 4 * PI * ballRadius * ballRadius);
    printf("Volume of the outer ball = %.2lf\n", 4.0 / 3 * PI * ballRadius * ballRadius * ballRadius);

    printf("Volume of the cylinder = %.2lf\n", bottomArea * h);

    return 0;
}
