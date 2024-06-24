#include<stdio.h>
//time complexity O(N^2)
//space complexity O(1)
int main()
{

    int a[]={8,4,1,3,2};
    int value,i,hole;
    for(i=1;i<5;i++)
    {

        value=a[i];
         hole=i;
         while(hole>0 && a[hole-1]>value)
         {

             a[hole]=a[hole-1];
             hole--;
         }
         a[hole]=value;
    }
    printf("sorted array");
    for(i=0;i<5;i++)
    {

        printf("%d ",a[i]);
    }

}
