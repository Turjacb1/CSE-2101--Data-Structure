/*#include <stdio.h>
#include <stdlib.h> 

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL; 
struct Node *rear = NULL;

void enqueue(int x) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) { // Handle memory allocation failure
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) { // Handle first element insertion
        front = rear = newnode;
    } else {
        rear->next = newnode; // Add new node to the end
        rear = newnode;
    }
}

void dequeue() {
    if (front == NULL && rear == NULL) { // Check for empty queue
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;
    front = front->next;
       printf("the deque element is %d ",front->data);

    if (front == NULL) { // Handle single-element queue becoming empty
        rear = NULL;

    }

    free(temp);
    
}

void display() {
    if (front == NULL && rear == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct Node *temp = front;
    printf("the element is =");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    enqueue(5);
    enqueue(8);
    enqueue(66);

    display(); // Output: 5 8 66

    dequeue();
    printf("\n");
    display(); // Output: 8 66

    return 0;
}*/




#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int data)
{
struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
if(newnode==NULL)
{
    printf("memory allocation failed");
    return;
}
newnode->data=data;
newnode->next=NULL;

if(front==NULL && rear==NULL)
{
    front=rear=newnode;
}
else{
    rear->next=newnode;
    rear=newnode;
}

}

void dequeue()
{
    if(front==NULL && rear==NULL)
    {
        printf("queue is empty ");
        return;
    }

    struct Node *temp=front;
 
    printf(" pop element = %d ",front->data);
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    free(temp);

}


void display()
{
    struct Node *temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }

}


void main()
{
    enqueue(33);
    enqueue(66);
    enqueue(77);
    display() ;
    
    dequeue();
printf("\n");
    display();

}

