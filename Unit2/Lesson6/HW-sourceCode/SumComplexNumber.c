#include <stdio.h>
#include <stdlib.h>




struct complexNumber add(struct complexNumber,struct complexNumber);

struct complexNumber{
    float real;
    float img;
};


int main()
{
    struct complexNumber firstNumber;
    struct complexNumber secondNumber;
    struct complexNumber result;
    printf("For 1st complex number\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f",&firstNumber.real);
    scanf("%f",&firstNumber.img);

    printf("For 2nd complex number\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f",&secondNumber.real);
    scanf("%f",&secondNumber.img);

    result = add(firstNumber, secondNumber);
    printf("Sum=%.2f+%.2fi",result.real,result.img);
    return 0;
}

struct complexNumber add(struct complexNumber first,struct complexNumber second)
{
    struct complexNumber result;
    result.real = first.real+second.real;
    result.img = first.img+second.img;
    return result;
}




