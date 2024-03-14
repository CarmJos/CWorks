// This project is a part of CWorks (C language practice project).
//     Copyright (C) 2024. CarmJos
//
//     This program is free software: you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation, either version 3 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License
//     along with this program.  If not, see <https://www.gnu.org/licenses/>.

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
