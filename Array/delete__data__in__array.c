
#include<stdio.h>
int main(){

int array[50],size,position,number;
printf("size of array = ");

scanf("%d",&size);

for(int i =0;i<=size-1;i++)
{

    scanf("%d",&array[i]);
}

for( int i =0;i<=size-1;i++)
{

    printf("show array element =%d\n",array[i]);
}

printf("enter your data what you want DELETE: ");

scanf("%d",&position);


for(int i=position-1;i<size-1;i++)
{

    array[i]=array[i+1];
}

size--;

for(int i =0;i<=size-1;i++)
{

    printf("after insert the array element =%d\n",array[i]);
}

return ;
}
