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

#include<stdio.h>
#include<stdlib.h>

typedef struct student {
    int num;
    char name[20];
    char sex;
    int age;
    float score;
    char addr[30];
} Student;

int main() {

    Student student;
    Student *p = &student;

    printf("Please input student's information: ");

    printf("\nnum: ");
    scanf("%d", &p->num);

    printf("\nname: ");
    scanf("%s", p->name);

    getchar();
    printf("\nsex (0=female,1=male): ");
    scanf("%c", &p->sex);

    printf("\nage: ");
    scanf("%d", &p->age);

    printf("\nscore: ");
    scanf("%f", &p->score);

    printf("\naddress: ");
    scanf("%s", p->addr);

    printf("Student's information: \n");
    printf("| num \t| name \t| sex \t| age \t| score \t| address \t|\n");
    printf(
            "| %d \t| %s \t| %c \t| %d \t| %.2f \t| %s \t|\n",
            p->num, p->name, p->sex, p->age, p->score, p->addr
    );

    return 0;
}
