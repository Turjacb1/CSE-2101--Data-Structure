/*#include <stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if (rear == N - 1) {
        printf("Overflow\n"); 
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Underflow\n"); 
    } else if (front == rear) {
        front = rear = -1; // 
    } else {
        printf("%d ", queue[front]); 
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n"); 
    } else {
        for (int i = front; i <= rear; i++) { 
            printf("%d ", queue[i]);
        }
        printf("\n"); 
    }
}

int main() {
    enqueue(55);
    enqueue(77);
    enqueue(33);
    display();
    dequeue();
    display();
    return 0; 
}*/

#include<stdio.h>
#define N 5
int queue[N];
int front=-1,rear=-1;

void endeque(int x)
{
    if(rear== N-1)
    {
        printf("overflow");
    }
    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(rear==-1 && front==-1)
    {
        printf("underflow");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        printf(" pop item = %d",queue[front]);
        front++;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        for(int i=front;i<rear+1;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}

void main()
{
    endeque(11);
    endeque(22);
    endeque(33);
    display();
    dequeue();
}