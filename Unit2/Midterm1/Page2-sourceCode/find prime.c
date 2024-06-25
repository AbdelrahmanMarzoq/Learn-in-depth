#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void getPrime(int,int);

int main()
{
    int start,end;
    printf("Enter two numbers(interval): ");
    scanf("%d %d",&start,&end);
    getPrime(start,end);
    return 0;
}


void getPrime(int start, int end)
{
    int prime;
    printf("Prime number between %d and %d are: ",start , end);
    for(int i = start; i <= end; i++)
    {
        prime = 1;
        for(int counter = 2; counter < sqrt(i); counter++)
        {
            if (i%counter == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime) printf("%d ",i);
    }

}
