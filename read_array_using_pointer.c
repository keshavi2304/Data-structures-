#include <stdio.h>
int main()
{
    int a[10],*p, i;
    p=a;
    printf("enter the 5 element: \n");
    for (i=0; i<5; i++)
    {

        scanf("%d",p);
        p++;
    }
    p=a;
        for(i=0; i<5;i++)
    {
        printf("%d",*p);
    p++;
    }
    return 0;
    }
