#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Enter an integer: ");
    scanf("%d",&x);
    long long sum;
    sum = (x*(x+1))/2;
    printf("Sum = %d",sum);

    return 0;
}


