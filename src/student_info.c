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
