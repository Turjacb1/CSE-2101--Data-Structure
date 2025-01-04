#include <stdio.h>
#include <stdlib.h>

#define MAX 5  

int deque[MAX];
int front = -1;
int rear = -1;


int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}


int isEmpty() {
    return (front == -1);
}


void insertFront(int key) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (front == -1) {  
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX - 1;  
    } else {
        front = front - 1;
    }

    deque[front] = key;
    printf("Inserted %d at the front.\n", key);
}




void insertRear(int key) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (rear == -1) {  
        front = 0;
        rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;  
    } else {
        rear = rear + 1;
    }

    deque[rear] = key;
    printf("Inserted %d at the rear.\n", key);
}



void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("Deque elements  ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}


int main() {
    insertRear(5);
    displayDeque();

     insertFront(15);
    displayDeque();

    insertRear(25);
    displayDeque();

    return 0;
}