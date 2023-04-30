#include <stdio.h>
#include <time.h>
int main()
{
    int i,j;
    int a[2][2], b[2][2], c[2][2];
    int s[10], p[8];
    clock_t start, end;
    printf("Enter the elements of first matrix:");
    for(int i=0;i<2;i++)
    {
        for (int j = 0; j <2; j++)
        {
            scanf("%d",&a[i][j]);
        }
        

    }

    printf("Enter the elements of second matrix:");
    for(int i=0;i<2;i++)
    {
        for (int j = 0; j <2; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    
s[0]=b[0][1]-b[1][1];
s[1]=a[0][0]+a[0][1];
s[2]=a[1][0]+a[1][1];
s[3]=b[1][0]-b[0][0];
s[4]=a[0][0]+a[1][1];
s[5]=b[0][0]+b[1][1];
s[6]=a[0][1]-a[1][1];
s[7]=b[1][0]+b[1][1];
s[8]=a[0][0]-a[1][0];
s[9]=b[0][0]+b[0][1];

for(int i=0;i<10;i++)
{
    printf("S%d: %d",(i+1),s[i]);
    printf("\n");
}

p[0]=s[0]*a[0][0];
p[1]=s[1]*b[1][1];
p[2]=s[2]*b[0][0];
p[3]=s[3]*a[1][1];
p[4]=s[4]*s[5];
p[5]=s[6]*s[7];
p[6]=s[8]*s[9];

printf("\n");
for(i=0;i<7;i++)
{
printf("P%d: %d",(i+1),p[i]);
printf("\n");
}
c[0][0]=p[4]+p[3]-p[1]+p[5];
c[0][1]=p[0]+p[1];
c[1][0]=p[2]+p[3];
c[1][1]=p[4]+p[0]-p[2]-p[6];

printf("\nMatrix A =");
for(i=0;i<2;i++)
{
printf("\n");
for(j=0;j<2;j++)
{
printf("%d\t",a[i][j]);
}
}
printf("\n\nMatrix B =");
for(i=0;i<2;i++)
{
printf("\n");

for(j=0;j<2;j++)
{
printf("%d\t",b[i][j]);
}
}
printf("\n\nMatrix C =");
for(i=0;i<2;i++)
{
printf("\n");
for(j=0;j<2;j++)
{
printf("%d\t",c[i][j]);
}
}
printf("\n");
end=clock();
double diff=(double)((end-start)/CLOCKS_PER_SEC);
return 0;
}
