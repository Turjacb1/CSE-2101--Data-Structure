#include<stdio.h>
int main()
{
 int size;
    int arr[100];
    int item,i;

    printf(" size of array = ");
    scanf("%d", &size);

    printf("elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter your search item = ");
    scanf("%d", &item);

    //runtime complexity 0(N)
    //space complexity 0() cause  use only one array


    for(i=0;i<6;i++)
    {
        if(arr[i]==item)
        {

            printf("item of found of index");
            return 0;
        }



    }
    printf("not found");
}
