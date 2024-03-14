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
