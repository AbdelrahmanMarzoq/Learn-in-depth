#include <stdio.h>
#include <stdlib.h>



struct distance{
    int feet;
    float inch;
};

int main()
{
    struct distance D1,D2,res;
    int x;
    printf("Enter information for 1st distance\n");
    printf("Enter feet: ");
    scanf("%d",&(D1.feet));
    printf("Enter inch: ");
    scanf("%f",&(D1.inch));
    printf("Enter information for 2nd distance\n");
    printf("Enter feet: ");
    scanf("%d",&(D2.feet));
    printf("Enter inch: ");
    scanf("%f",&(D2.inch));

    res.feet = D1.feet + D2.feet;
    res.inch = D1.inch + D2.inch;
    x = (int)res.inch/12;
    res.inch -= x*12 ;
    res.feet += x;
    printf("Sum of distances = %d\'-%.1f\"",res.feet,res.inch);
    return 0;
}





