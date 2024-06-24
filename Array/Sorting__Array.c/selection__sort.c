#include <stdio.h>

int main() {
    int arr[] = {6, 5, 88, 44, 90, 23};
    int minindex, i, j;

    for (i = 0; i < 6; i++) {
        minindex = i;

        for (j = i + 1; j < 6; j++) {
            if (arr[j] < arr[minindex]) {  // Corrected condition
                minindex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }

    for (i = 0; i < 6; i++) {
        printf("%d\n", arr[i]);
    }

    printf("\n");
    return 0;
}
