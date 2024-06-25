#include <stdio.h>
#include <stdlib.h>


void reverse(char *begin, char *end);
void reverseWords(char *);
int main()
{
    char str[100] = {0};
    printf("Enter your sentence: ");
    gets(str);
    reverseWords(str);
    printf("Your string after reversed word : %s",str);

    return 0;
}


void reverse(char *begin, char *end)
{
    char temp;
    while(begin < end)
    {
        temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

void reverseWords(char *myString)
{
    char *begin = myString;
    char *temp = myString;
    while(*temp != '\0')
    {
        temp++;
        if (*temp == ' ')
        {
            reverse(begin,temp-1);
            begin = temp+1;
        }
        else if (*temp == '\0')
        {
            reverse(begin,temp-1);
        }
    }

    reverse(myString, temp-1);
}


