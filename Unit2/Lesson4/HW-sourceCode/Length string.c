#include <stdio.h>
#include <stdlib.h>


int main()
{
    char string[1000];
    int length = 1;
    printf("Enter a string: ");
    getchar();
    gets(string);

    while (NULL != string[length])
    {
        length++;
    }
    length++;
    printf("Length of string: %d",length);
    return 0;
}




