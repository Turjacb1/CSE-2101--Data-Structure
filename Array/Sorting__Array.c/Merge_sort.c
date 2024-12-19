#include <stdio.h>
void merge(int arr[], int l, int mid, int r) {

    int n1 = mid - l + 1;
    int n2 = r - mid;



    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
    {

        a[i] = arr[l + i];

    }



    for (int i = 0; i < n2; i++) {
        b[i] = arr[mid + 1 + i];  
    }




    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}


void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r-l) / 2;
       

        mergesort(arr, l, mid);
       
        mergesort(arr, mid + 1, r);
        

        merge(arr, l, mid, r);
    }
}


int main() {
    int arr[] = {5, 4, 3, 2, 1,88,66,22,55,99,33};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("size of n = %d\n ",n);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}





