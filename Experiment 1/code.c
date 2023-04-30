
#include <stdio.h>
#include <math.h>
#include <conio.h>

long factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int num;
    int a;
    int first;
    double b,c,d,f,e,g,h,i;
    int val;
    int j;
    long facto;

    printf("Input\t\tn  n^3  2^n  n.2^n  n.lg(n)  2^(2^n+1)  (3/2)^n  lg(n)  lg(n)^2  lg(n)^1/2\n");
    for(num=1; num<=100; num++)
    {
        first=num;
        a=num*num*num;
        b=pow(2,num);
        c=num*pow(2,num);
        d=num*log2(num);
        f=pow(1.5,num);
        g=log2(num);
        h=pow(log2(num),2);
        e=pow(2,g);
        i=sqrt(g);
        printf("%d\t%d\t%d\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f\t%0.3f",num,first,a,b,c,d,e,f,g,h,i);
        printf("\n");
    }

    for (j=1; j<=20; j++)
    {
        facto=factorial(j);
        printf("%d\t%ld",j,facto);
        printf("\n");
    }


    return 0;
}
