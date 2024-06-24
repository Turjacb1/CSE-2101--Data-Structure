
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *creatlinkedlist(int arr[], int size);
void reverselinkdelist(struct Node *head);



int main() {
    int a[] = {5, 10, 30};
    struct Node *head=NULL;
    head = creatlinkedlist(a, 3);


    struct Node *newhead=head;
    while (head != NULL) {
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL\n");
    reverselinkdelist(newhead);
    return 0;
}

void reverselinkdelist(struct Node *head)
{

    struct Node *prev=NULL,*current=head,*next=NULL;

    while(current !=NULL)
    {
        //store the next node
        next=current->next;

        //reverse the link
        current->next=prev;
        //propagete
        prev=current;
        current=next;
    }
    head = prev;
    while (head != NULL) {
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("NULL\n");

}

struct Node *creatlinkedlist(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;
    for (i = 0; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("Memory allocation ");
            exit(1);
        }
        temp->data = arr[i];
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            current = temp; // Initialize current if head is NULL
        } else {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}
