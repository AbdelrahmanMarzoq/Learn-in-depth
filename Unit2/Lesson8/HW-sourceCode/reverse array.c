#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int arr[16];
    int size;

    printf("Enter size of array:\n");
    scanf("%d",&size);
    printf("Enter %d number of the elements in the array:\n",size);
    for(int i = 0; i < size; i++)
    {
        printf("element -%d : ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The elements of array in reverse order are:\n");
    for(int i = 1; i <= size; i++)
    {
        printf("element - %d : %d \n", (size-i+1),*(arr+size-i));
    }
    return 0;
}
