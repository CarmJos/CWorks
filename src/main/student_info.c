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

void get_student(Student *p) {
    printf("\n- Student's ID: ");
    scanf("%d", &p->num);

    printf("\n- Student's name: ");
    scanf("%s", p->name);

    getchar();
    printf("\n- Student's sex: ");
    scanf("%c", &p->sex);

    printf("\n- Student's age: ");
    scanf("%d", &p->age);

    printf("\n- Student's score: ");
    scanf("%f", &p->score);

    getchar();
    printf("\n- Student's address: ");
    gets(p->addr);
}

void put_student(Student *p) {
    printf(
            "| %d\t | %s\t | %c\t | %d\t | %.2f\t | %s\n",
            p->num, p->name, p->sex, p->age, p->score, p->addr
    );
}

int main() {
    Student student;
    Student *p = &student;

    printf("Please input student's information: ");
    get_student(p);

    printf("\n");
    printf("| id\t | name\t | sex\t | age\t | score\t | address\n");
    put_student(p);

    return 0;
}
