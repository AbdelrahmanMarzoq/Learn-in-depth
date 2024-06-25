#include <stdio.h>
#include <stdlib.h>


struct Student{
    char studentName[30];
    float mark;
};


int main()
{
    struct Student group[10];

    for(int i = 0; i < 10; i++)
    {
        printf("For roll number %d\n",i+1);
        printf("Enter name: ");
        gets(group[i].studentName);
        printf("Enter marks: ");
        scanf("%f",&(group[i].mark));
        getchar();
    }

    printf("Displaying information of students: \n");
    for(int i = 0; i < 10; i++)
    {
        printf("For roll number %d\n",i+1);
        printf("name: %s\n",group[i].studentName);
        printf("marks: %f\n",group[i].mark);
    }
    return 0;
}




