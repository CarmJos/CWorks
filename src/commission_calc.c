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

const int UNIT = 100000;

double calcCommission(int total, int left, int right, double ratio) {
    if (total < left) return 0;
    if (right > 0 && total >= right) return (right - left) * ratio;
    return (total - left) * ratio;
}

double calcCommissionWithUnit(int total, int left, int right, double ratio) {
    return calcCommission(total, left * UNIT, right * UNIT, ratio);
}

double calculateByIf(int total) {
    double sum = 0;
    sum += calcCommissionWithUnit(total, 0, 1, 0.1);
    sum += calcCommissionWithUnit(total, 1, 2, 0.075);
    sum += calcCommissionWithUnit(total, 2, 4, 0.05);
    sum += calcCommissionWithUnit(total, 4, 6, 0.03);
    sum += calcCommissionWithUnit(total, 6, 10, 0.015);
    sum += calcCommissionWithUnit(total, 10, -1, 0.01);
    return sum;
}

double calculateBySwitch(int total) {
    if (total <= 0) return 0;
    // (left,right] required to minus 1 to prevent issues.
    switch ((total - 1) / UNIT) {
        case 0:
            return total * 0.1;
        case 1:
            return 10000 + (total - UNIT * 1) * 0.075;
        case 2:
        case 3:
            return 17500 + (total - UNIT * 2) * 0.05;
        case 4:
        case 5:
            return 27500 + (total - UNIT * 4) * 0.03;
        case 6:
        case 7:
        case 8:
        case 9:
            return 33500 + (total - UNIT * 6) * 0.015;
        default:
            return 39500 + (total - UNIT * 10) * 0.01;
    }
}

int main() {

    int i;
    printf("Please input the profit(I): \n");
    scanf("%d", &i);

    if (i < 0) {
        printf("Illegal input.");
        return 0;
    }

    printf("By if condition -> W = %.2f\n", calculateByIf(i));
    printf("By switch statement -> W = %.2f\n", calculateBySwitch(i));

    return 0;
}
