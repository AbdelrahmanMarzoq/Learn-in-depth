/**  get fourth bit value */
int _4thbit (int num)
{
    int bit;
    bit = 1 & (num>>3);
    return bit;
}

/** check if input string is USERNAME or not*/
void Same(void)
{
    char x[100];
    int y;
    gets(x);
    y = strcmp(x, "USERNAME");
    if (y == 0) printf("SAME");
    else printf("not same")
}


/**  check if num power to 3 */
int check3 (int num)
{
    if (num != 1 && num%3 == 0)
        return 0;
    else
        return 1;
}

/**  convert decimal to array of ASCII  */
int convert_to_ASCII (unsigned int num)
{
    unsigned int n = num;
    int mod;
    char ASCII[11];
    int i = 0;
    while(n)
    {
        mod = n%10;
        n = n / 10;
        ASCII[i++] = mod + '0';
    }
}
/** reverse input array */
void reverse_array(int size_array)
{
    int arr[100];
    int temp;
    for (int i = 0; i < size_array; i++)
    {
        scanf("%d",&arr[i]);
    }
    int j = size_array-1;
    for(int i = 0; i < j; i++)
    {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j--;
    }
    for (int i = 0; i < size_array; i++)
    {
        printf("%d",arr[i]);
    }
}

/** clear specific bit */
void CLR_BIT(int num, int bit_pos)
{
    num &= ~(1>>bit_pos);
}

/**  find index of last occurence of number in array*/
int LAST_OCCUR(int num, int arr[], int size)
{
    int x;
    int flag = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            x = i;
            flag = 1;
        }
    }
    if (flag) return x;
    else return -1;
}

/** Swap 2 array with diffrenct length*/
int SWAPP_2ARR(int A[], int B[], int size_A, int size_B)
{
    int temp;
    int x = size_A > size_B? size_B: size_A;
    for (int i = 0; i < x; i++)
    {
        temp = A[i];
        A[i] = B[i];
        B[i] = A[i];
    }
}



