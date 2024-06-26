
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

