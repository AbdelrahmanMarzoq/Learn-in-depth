#include <stdio.h>
#include <stdlib.h>



int calcSum(int);

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    int res = calcSum(num);
    printf("The sum of digits of number %d = %d", num, res);
    return 0;
}


int calcSum(int num)
{
    static unsigned short new_num = 0;
    int rem;
    if(num != 0)
    {
        rem = num%10;
        new_num += rem;
        calcSum(num/10);
    }
    else return 0;
    return new_num;
}


