#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int freq[28];
int main()
{
    char string[10000];
    char ch;
    printf("Enter a string: ");
    getchar();
    gets(string);
    printf("Enter a character to find frequency: ");
    scanf("%c",&ch);
    char temp = ch;

    towlower(ch);
    int i = 0;

    while(NULL != string[i])
    {
        towlower(string[i]);
        freq[string[i]-'a']++;
        i++;
    }
    printf("Frequency of %c = %d",temp, freq[ch-'a']);

    return 0;
}



