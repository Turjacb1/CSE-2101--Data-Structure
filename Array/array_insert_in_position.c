#include <stdio.h>

int main() {
    int array[50], size, pos, number;

    printf("size of array = ");
    scanf("%d", &size);

  
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < size; i++) {
        printf("show array element = %d\n", array[i]);
    }

   
    printf("enter position: ");
    scanf("%d", &pos);
    printf("enter insert data: ");
    scanf("%d", &number);


   
    for (int i = size; i >= pos; i--) {
        array[i] = array[i - 1];
    }

    array[pos- 1] = number;
    size++;

    
    for (int i = 0; i < size; i++) {
        printf("after insert the array element = %d\n", array[i]);
    }

    return 0;
}
