#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int reverse(char[]);

int main()
{
    char str[100];
    printf("Enter a sentence: ");
    gets(str);
    reverse(str);
    printf("%s",str);
    return 0;
}


int reverse(char str[])
{
    int x = strlen(str);
    char temp;
    int j = x-1;
    for(int i = 0; i < j; i++)
    {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
        j--;
    }
}
