
#include <stdio.h>
#include <stdlib.h>

long long factorial (int num);

int main()
{
    int num;
    printf("Enter and integer: ");
    scanf("%d",&num);

    if (num < 0)
    {
        printf("Error!!! Factorial of negative number doesn`t exist.");
    }
    else
    {
        long long fact;
        fact = factorial(num);
        printf("Factorial = %d",fact);
    }


    return 0;
}


long long factorial (int num)
{
    long long fact = num;
    if (0 != num)
    {
        fact = fact * factorial(num-1);
    }
    else
    {
        return 1;
    }
    return fact;

}
