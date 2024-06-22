#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Enter an alphabet: ");
    scanf("%c", &ch);

    if ('a' == ch || 'e' == ch || 'i' == ch || 'o' == ch || 'u' == ch)
    {
        printf("%c is vowel.", ch);
    }
    else if ('A' == ch || 'E' == ch || 'I' == ch || 'O' == ch || 'U' == ch)
    {
        printf("%c is vowel.", ch);
    }
    else
    {
        printf("%c is consonant.", ch);
    }
    return 0;
}
