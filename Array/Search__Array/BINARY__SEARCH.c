#include <stdio.h>

// Runtime complexity = O(log N)
// Space complexity = O(1)
int main() {
    int size;
    int arr[100];
    int item;

    printf(" size of array = ");
    scanf("%d", &size);

    printf("elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter your search item = ");
    scanf("%d", &item);

    int left, right, middle;
    left = 0;
    right = size - 1;  

    while (left <= right) {
        middle = (left + right) / 2;
        if (arr[middle] == item) {
            printf("Item found at index: %d\n", middle);
            return 0;
        } else if (arr[middle] < item) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    printf("Item not found\n");
    return 0;
}
