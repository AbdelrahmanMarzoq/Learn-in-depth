#include <stdio.h>
#include <stdlib.h>


int main()
{
    char Operator;
    float num1, num2;
    printf("Enter operator either + or - or * or divide: ");
    scanf("%c",&Operator);
    printf("Enter two operands: ");
    scanf("%f",&num1);
    scanf("%f",&num2);

    float result;

    switch(Operator)
    {
    case '+':
        result = num1 + num2; break;
    case '-':
        result = num1 - num2; break;
    case '*':
        result = num1 * num2; break;
    case '/':
        result = num1/num2;break;
    }
    printf("%f %c %f = %f", num1, Operator, num2, result);
    return 0;
}




