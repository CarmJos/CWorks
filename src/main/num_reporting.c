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

// N 个人围成一圈，顺序从1~3报数，若报到3则离开队伍
// 最后剩下的是第几个人

int first_in(const int *people, int n) {
    for (int i = 0; i < n; ++i) {
        if (people[i] != 0) {
            return people[i];
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    // Initialize people's index
    int people[n];
    for (int i = 0; i < n; ++i) {
        people[i] = i + 1;
    }

    // Start counting, 1~3 ,remove all 3
    int count = 0;
    int left = n;
    int i = 0;
    while (left > 1) {
        if (people[i] != 0) { // If this person is not removed
            count++;
            if (count == 3) {
                people[i] = 0; // Remove this person
                count = 0; // reset count
                left--; // left people -1
            }
        }
        i = (i + 1) % n; // loop for i;
    }

    printf("\nThe last person is: %d\n", first_in(people, n));
    return 0;
}