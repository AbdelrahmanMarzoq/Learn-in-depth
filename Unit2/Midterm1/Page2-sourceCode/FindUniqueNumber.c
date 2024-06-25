#include <stdio.h>
#include <stdlib.h>

int findUnique(int a[], int size);

int main()
{
    int a[7] = {4,2,5,2,5,7,4};
    int x;
    int size = sizeof(a)/sizeof(a[0]);

    x = findUnique(a, size);
    printf("%d",x);
    return 0;
}

int findUnique(int a[], int size)
{
    int flag = 1;
    int res;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(a[i] == a[j])
            {
                if(i != j)
                {
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            res = a[i];
            break;
        }
    }
    return res;
}

