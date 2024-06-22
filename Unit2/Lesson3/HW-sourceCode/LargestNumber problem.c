
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%f" ,&num1);
    scanf("%f" ,&num2);
    scanf("%f" ,&num3);

    if (num1 >= num2)
    {
        if (num1 > num3)
        {
            printf("Largest number = %.2f",num1);
        }
        else
        {
            printf("Largest number = %.2f",num3);
        }
    }
    else
    {
        if (num2 > num3)
        {
            printf("Largest number = %.2f",num2);
        }
        else
        {
            printf("Largest number = %.2f",num3);
        }
    }
    return 0;
}

