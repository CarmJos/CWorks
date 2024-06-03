#include <stdio.h>

/**
 * 编写一个程序，实现从键盘输入3个学生数据(每个学生的数据包括学号、姓名、2门课程成绩的)，
 * 输出每个学生2门课总平均成绩，以及最高分的学生的数据(包括学号、姓名、2门课的成绩、平均分数)
 */

// 定义学生结构体
typedef struct student {
    int id;
    char name[50];

    float score1;
    float score2;
    float average;
} Student;

int main() {

    int size = 0;
    printf("Enter the number of students: ");
    scanf("%d", &size);

    Student students[size];

    int i, top_student_index = 0;
    float highest_average = 0.0f;

    // 输入学生数据
    for (i = 0; i < size; i++) {
        printf("\nEnter details for student %d:", i + 1);
        printf("\n| ID:  ");
        scanf("%d", &students[i].id);
        printf("\n| Name:  ");
        scanf("%s", students[i].name);
        printf("\n| Score for course 1:  ");
        scanf("%f", &students[i].score1);
        printf("\n| Score for course 2:  ");
        scanf("%f", &students[i].score2);

        // 计算平均成绩
        students[i].average = (students[i].score1 + students[i].score2) / 2;

        // 找到最高平均成绩的学生
        if (students[i].average > highest_average) {
            highest_average = students[i].average;
            top_student_index = i;
        }

    }

    // 输出每个学生的平均成绩
    printf("\nID \t Name \t Average\n");
    for (i = 0; i < size; i++) {
        printf("%d \t %s \t %.2f\n", students[i].id, students[i].name, students[i].average);
    }

    // 输出最高分学生的数据
    printf("\nTop student:\n");
    printf("ID: %d, Name: %s, Score1: %.2f, Score2: %.2f, Average: %.2f\n",
           students[top_student_index].id, students[top_student_index].name,
           students[top_student_index].score1, students[top_student_index].score2,
           students[top_student_index].average);

    return 0;
}
