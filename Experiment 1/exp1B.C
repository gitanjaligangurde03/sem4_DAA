#include <stdio.h>
#include <time.h>


void insertion(int arr[],int size){
    int i;
    int j;
    int key;
    for(int i=0;i<size;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}


void selection(int a[], int len)
{ 
    int i,j,key;
    int min,temp;
    for(i=0; i<len-1; i++)
    {
        min=i;
        for(j=i+1; j<len; j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }


}


int main()
{
    
    int data,len;

    FILE *fptr;
    fptr=fopen("variables.txt","r");
    int a[100000];
    int i=0;
    int num;
   while(fscanf(fptr," %d", num)>0)
    {
        a[i]=num;
        i++;
    }
    fclose(fptr);
    for (int i = 0; i < 1000; i++)
    {
        int a1[100*(i+1)];
        int a2[100*(i+1)];
    for(int j=0;j<100*(i+1);j++){
        a1[j]=a[j];
        a2[j]=a[j];
    }

    clock_t start=clock();
    selection(a1,100*(i+1));
    clock_t end=clock();
    double diff=((double)end-start)/CLOCKS_PER_SEC;

    clock_t start1=clock();
    insertion(a2,100*(i+1));
    clock_t end2=clock();
    double diff1=((double)end2-start1)/CLOCKS_PER_SEC;
    
    printf("%d\t%lf\t",i+1,diff);
    printf("%lf\n",diff1);
    }
    return 0;
}
