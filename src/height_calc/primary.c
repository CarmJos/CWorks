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
