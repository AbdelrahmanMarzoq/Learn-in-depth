#include <stdio.h>
#include <stdlib.h>



float squarRoot(float num);
int main()
{
    float num;
    printf("Enter a number: ");
    scanf("%f",&num);
    float sqr = squarRoot(num);
    printf("%.2f",sqr);
    return 0;
}

float squarRoot(float num)
{
    float i;
    for (i = 0.01; i*i < num; i +=0.01)
    {
    }
    return i;
}


