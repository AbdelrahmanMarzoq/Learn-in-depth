#include <stdio.h>
#include <stdlib.h>



int ones(int);

int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    int res = ones(x);
    printf("Number of ones bit in %d = %d", x, res);
    return 0;
}

int ones(int num)
{
    int counter = 0;
    while(num!=0)
    {
        counter += num&1 ;
        num >>= 1;
    }
    return counter;
}

