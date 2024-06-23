#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int getPower(int base, int power);


int main()
{
    int base,power;
    printf("Enter base number: ");
    scanf("%d",&base);
    printf("Enter power number (positive integer): ");
    scanf("%d",&power);
    int result = getPower(base,power);
    printf("%d",result);
    return 0;
}


int getPower(int base, int power)
{
    int result = base;
    if(power > 0)
    {
        result *=getPower(base,--power);
    }
    else return 1;
    return result;
}

