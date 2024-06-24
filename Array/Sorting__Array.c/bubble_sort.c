#include <stdio.h>


//time complexity =0(n^2)
//space complexity =0(1)
int main() {
    int arr[] = {5,9,2,88,67,82};
    int i, j, size = 6;


    int swap,counter=0;
    for (i = 0; i < size - 1; i++) {
            swap=0;
        for (j = 0; j < size - 1 - i; j++) {

                counter++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
    swap=1;
            }
        }
        if(swap==0)
        {
            break;
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("total loop\n %d",counter);

    return 0;
}
