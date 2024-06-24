#include <stdio.h>
#include <stdlib.h>



int reverse(int);

int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    int rev = reverse(x);
    printf("The reversed digits of num %d = %d",x,rev);
    return 0;
}

int reverse(int num)
{
    int rem;
    int d = 0;
    while(num!=0)
    {
        rem = num%10;
        d  = d*10 + rem;
        num = num / 10;
    }
    return d;
}

