#include <stdio.h>
#include <stdlib.h>


#define AREA(r) 3.14*r*r
int main()
{
    float radius;
    printf("Enter the radius: ");
    scanf("%f",&radius);
    printf("Area=%.2f",AREA(radius));
    return 0;
}




