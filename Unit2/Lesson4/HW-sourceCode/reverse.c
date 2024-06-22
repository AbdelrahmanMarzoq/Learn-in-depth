#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[1000];
char reverse[1000];

int main()
{
    char string[1000];
    char reverse[1000];
    printf("Enter a string    : ");
    gets(string);

    int size = strlen(string);
    size--;
    int j = 0;
    for (int i = size; i >= 0; i--)
    {
        reverse[j] = string[i];
        j++;
    }
    printf("Reverse string is : %s",reverse);

    return 0;
}




