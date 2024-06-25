#include <stdio.h>
#include <stdlib.h>



int maxOnes(int);

int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    int res = maxOnes(x);
    printf("Max ones between 2 zeros of %d = %d", x, res);
    return 0;
}

int maxOnes(int num)
{
    int counter = 0;
    int tempCounter = 0;
    while(num!=0)
    {
        if(num&1)
        {
            counter++;
        }
        else
        {
            if(counter > tempCounter)
            {
                tempCounter = counter;
            }
            counter = 0;
        }
        num >>= 1;
    }
    if(counter > tempCounter)
    {
        tempCounter = counter;
    }

    return tempCounter;
}
