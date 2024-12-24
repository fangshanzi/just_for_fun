/*
    program description:
    input:
        row number
    output:
        the specified row of the yanghui's triangle
*/

#include <stdio.h>
#include <stdlib.h>

void fun(double * const l,double * const k,int n);

int main()
{
    int n=0;
    int i;
    printf("Input the row number (not under 3): ");
    scanf("%d",&n);
    double a[2][n];
    a[0][0]=1;
    a[0][1]=1;

    for(i=3;i<=n;i++)
    {
        if(i%2==1)
            fun(a[0],a[1],i);
        else
            fun(a[1],a[0],i);
    }

    if(i%2==0)
        for(i=0;i<n;i++)
            printf("%g ",a[1][i]);
    else
        for(i=0;i<n;i++)
            printf("%g ",a[0][i]);

    printf("\n");
    system("pause");
    return 0;
}

