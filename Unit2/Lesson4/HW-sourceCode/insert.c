#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int num, arr[1000+1], index, data;
    printf("Enter number of element : ");
    scanf("%d",&num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be inserted : ");
    scanf("%d",&data);
    printf("Enter the location : ");
    scanf("%d",&index);
    index--;
    for (int i = num; i >= index ; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[index] = data;

    for (int i = 0; i <= num; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}



