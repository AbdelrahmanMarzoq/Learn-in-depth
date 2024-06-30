#include <stdio.h>
#include <stdlib.h>


int main()
{
    char x = 'A';
    char *PTR = &x;
    printf("The Alphabets are: \n");
    for( ; *PTR <= 'Z'; (*PTR)++)
    {
        printf("%c ",*PTR);
    }
    return 0;
}
