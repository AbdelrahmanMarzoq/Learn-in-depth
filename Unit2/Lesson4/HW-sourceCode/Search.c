#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int num, arr[1000], data, location, flag;

    printf("Enter no of element : ");
    scanf("%d",&num);

    for(int i = 0; i < num; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&data);
    for(int i = 0; i < num; i++)
    {
        if (arr[i] == data)
        {
            location = i+1;
            flag = 1;
            break;
        }
    }
    if (flag) printf ("Number found at the location = %d",location);
    else printf("Number not found");
    return 0;
}




