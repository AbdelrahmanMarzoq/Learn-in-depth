#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[100], temp;
    char *begin = string;
    char *end;
    int size;

    gets(string);
    size = strlen(string);
    end = string;
    end += size - 1;

    while(begin < end)
    {
        temp = *end;
        *end = *begin;
        *begin = temp;
        begin++;
        end--;
    }
    begin = string;
    end = string + size -1;
    printf("%s",begin);
    return 0;
}
