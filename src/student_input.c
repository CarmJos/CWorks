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
