

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node*next;
    struct Node*prev;
};



struct Node* create_doubly_linkedlist(int arr[],int size)
{
struct Node*temp=NULL,*head=NULL,*current=NULL;

for(int i=0;i<size;i++)
{
    temp=(struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL)
    {
        printf("memory allocation failed");
        exit(1);
    }
    temp->data=arr[i];
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        temp->prev=NULL;
    }
    else
    {
        current->next=temp;
        temp->prev=current;
    }
    current=temp;
}
return head;
}

void delete__end__Node(struct Node **head)
{
    struct Node*temp=*head;
    if(*head==NULL)
    {
        return;
    }
    if((*head)->next ==NULL)
    {
        free(*head);
        *head=NULL;
        return;
    }
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
 }
 struct Node *lastnode=temp->next;
 temp->next=NULL;
 free(lastnode);
}



void printlist(struct Node*head)
{
    struct Node*temp=head;
    while(temp!=NULL)
    {
        printf(" %d-> ",temp->data);
        temp=temp->next;
    }
    printf("null");
}



int main()
{
    int arr[100],size;
    printf("enter your list size = ");
    scanf("%d",&size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    struct Node*head=create_doubly_linkedlist(arr,size);
    printf("orginal list = ");
    printlist(head);
    printf("\n");


    
    printf("after deleting end Node  = ");
    delete__end__Node(&head);
    printlist(head);
    return 0;
}