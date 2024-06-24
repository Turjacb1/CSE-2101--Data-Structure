#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *top=0;
void push(int x)
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;

}

void pop()
{
    struct Node *temp;
    temp=top;
    if(top==0)
    {
printf("underflow");        
    }
    else{
        printf("pop element = %d\n",top->data);
        top=top->next;
        free(temp);
    }
}

void peek()
{
    if(top==0)
    {
        printf("underflow");
    }

    else{
        printf("top element = %d",top->data);
    }
}
void display()
{
    struct Node *temp;
    temp=top;
    if(top==0)
    {
        printf("overflow");
    }
    else
    {
        while(temp!=0)
        {
            printf(" display element = %d\n",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    push(2);
    push(4);
    push(8);
    push(1);
    display();
    pop();
    display();
    pop();
    display();

    peek();
}
