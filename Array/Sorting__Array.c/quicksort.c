// void swap(int* p1, int* p2)
// {
//     int temp;
//     temp = *p1;
//     *p1 = *p2;
//     *p2 = temp;
// }




// int partition(int arr[], int low, int high)
// {
    
//     int pivot = arr[high];


//     int i = (low - 1);

//     for (int j = low; j <= high - 1; j++) {
     
//         if (arr[j] < pivot) {
        
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }




// void quickSort(int arr[], int low, int high)
// {
    
//     if (low < high) {
       
//         int pi = partition(arr, low, high);

//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }

// int main()
// {
//     int arr[] = { 10, 7, 8, 9, 1, 5 };
//     int n = sizeof(arr) / sizeof(arr[0]);
    
  
//     quickSort(arr, 0, n - 1);
  
  
//     printf("Sorted Array\n");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }









#include<stdio.h>
int main()
{
    int arr[]={12,33,9,3,5,20,44};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

return 0;

}



void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}




int partition(int arr[],int low,int high)

{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;

    
    

}



void swap(int* p1,int* p2)
{
    int temp=*p1;
    *p1=*p2;
    *p2=temp;    
}