#include <stdio.h>
#include <stdlib.h>


typedef struct Emplyee{
    char Name[30];
    int ID;
}emplyee;

int main()
{
    emplyee Alex = {"Alex",1002};
    emplyee *myEmployee = &Alex;
    printf("Employee Name : %s\n", myEmployee->Name);
    printf("Employee ID : %d", myEmployee->ID);
    return 0;
}
