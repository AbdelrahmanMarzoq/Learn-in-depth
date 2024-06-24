#include <stdio.h>
#include <stdlib.h>

int reverseArray(int a[], int size);

int main()
{
    int a[] = {1,2,3,4,5};
    int size = sizeof(a)/ sizeof(a[0]);
    reverseArray(a,size);
    printf("After reverse: ");
    for(int i = 0 ; i < size; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

int reverseArray(int a[], int size)
{
    int temp;
    int j = size-1;
    for(int i = 0; i < j; i++)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        j--;
    }
}

