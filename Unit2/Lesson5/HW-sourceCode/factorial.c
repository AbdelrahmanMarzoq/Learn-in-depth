#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int Fact(int);

int main()
{
    int num;
    int result;
    printf("Enter an positive integer: ");
    scanf("%d",&num);
    result = Fact(num);
    printf("Factorial of %d = %d",num ,result);
    return 0;
}


int Fact(int num)
{
    int result = num;
    if (num > 0)
    {
        result = result * Fact(num-1);
    }
    else
        return 1;
    return result;
}
