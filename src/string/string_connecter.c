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


// function to connect 2 char array with space without \n
void str_conn(char* str, const char* str1, const char connector) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    int j = 0;
    while (str1[j] != '\0') {
        if (str1[j] != '\n') {
            str[i] = str1[j];
            i++;
        }
        j++;
    }
    str[i] = connector;
}

int main() {
    char str1[50] = {0};
    char str2[50] = {0};

    printf("Input 2 parts of char array: \n");
    fgets(str1, 50,stdin);
    fgets(str2, 50,stdin);

    char str[100] = {0};
    str_conn(str, str1, ' ');
    str_conn(str, str2, ' ');

    printf("Final content ->  %s", str);

    return 0;
}
