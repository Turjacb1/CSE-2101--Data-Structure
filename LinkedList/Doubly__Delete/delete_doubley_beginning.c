

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
int data;
struct Node*next;
struct Node*prev;
};



struct Node* create_linkedlist(int arr[],int size)
{
struct Node *temp=NULL,*head=NULL,*current=NULL;
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
        head->prev=NULL;
    }
    else{
        current->next=temp;
        temp->prev=current;

    }
    current=temp;
}
return head;
}


void delete__first__Node(struct Node** head)
{
    if(*head==NULL)
    {
        return;
    }
    struct Node*temp=*head;
    *head=(*head)->next;
    if(*head!=NULL)
    {
        (*head)->prev=NULL;

    }
     free(temp);
     

}


void printlist(struct Node *head)
{
    struct Node *temp=head;
    while(temp!=NULL)
    {
        printf(" %d-> ",temp->data);
        temp=temp->next;
    }
    printf("null");
}

int main()
{
    int arr[]={10,20,30,40},size,i;
    printf("enter your size = ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    struct Node *head=create_linkedlist(arr,3);
    printf("orginal list = ");
    printlist(head);

    printf("\n");

    printf("after deleting first node = ");
    delete__first__Node(&head);
    printlist(head);
    return 0;
}