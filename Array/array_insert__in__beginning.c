#include <stdio.h>

int main() {
    int array[50], size, number;

    printf("size of array = ");
    scanf("%d", &size);

  
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++) {
        printf("show array element = %d\n", array[i]);
    }


    printf("enter insert data: ");
    scanf("%d", &number);


   
    for (int i = size; i >= 0; i--) {
        array[i] = array[i - 1];
    }

    array[0] = number;
    size++;

    
    for (int i = 0; i < size; i++) {
        printf("after insert the array element = %d\n", array[i]);
    }

    return 0;
}
