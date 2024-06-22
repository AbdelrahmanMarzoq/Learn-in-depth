#include <stdio.h>
#include <stdlib.h>



int main()
{
    int numData;

    printf("Enter the numbers of data: ");
    scanf("%d",&numData);
    float arr[100000];
    float Avr;
    for(int i = 0; i < numData;i++)
    {
        printf("%d. Enter number: ",(i+1));
        scanf("%f",&arr[i]);
        Avr += arr[i];
    }
    Avr /= numData;
    printf("Average = %f",Avr);

    return 0;
}




