#include <stdio.h>
#include <stdlib.h>





struct Student{
    char studentName[30];
    int rollNumber;
    float marks;
};

void getStudent(struct Student *newStudent);
void displayStudent(struct Student *newStudent);
int main()
{
    struct Student Ahmed;

    getStudent(&Ahmed);
    displayStudent(&Ahmed);

    return 0;
}

void getStudent(struct Student *newStudent)
{
    printf("Enter information of student:\n");
    printf("Enter name: ");
    gets(newStudent->studentName);
    printf("Enter roll nunber: ");
    scanf("%d",&(newStudent->rollNumber));
    printf("Enter marks: ");
    scanf("%f",&(newStudent->marks));
}

void displayStudent(struct Student *student)
{
    printf("Displaying information\n");
    printf("name: %s\n",student->studentName);
    printf("Roll: %d\n",student->rollNumber);
    printf("Marks: %.2f\n",student->marks);

}


