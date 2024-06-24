#include <stdio.h>

#define max 100 
int stack[max];
int top = -1; 

int isEmpty() {
    return top == -1;
}


int isFull() {
    return top == max - 1;
}


void push(int data) {
    if (isFull()) {
        printf("Stack Overflow =%d\n", data);
        return;
    }
    stack[++top] = data;
    printf("push element = %d ",data); 
}


int pop() {

    if (isEmpty()) 
    {
        printf("stack Underflow! ");
        return -1; 
    }
   
    return stack[top--]; 
}


int peek() {

    if (isEmpty()) 
    {
        printf("Stack is Empty");
        return -1; 
    }
    return stack[top];
}

int main() {
    
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    int popped = pop();
    printf("Popped element: %d\n", popped);

    printf("Top element after popping: %d\n", peek());

    return 0;
}
