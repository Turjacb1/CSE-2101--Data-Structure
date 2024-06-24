#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createlinkedlist(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    for (int i = 0; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("memory allocation failed");
            exit(1);
        }
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }
    return head;
}

void printlist(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delete_pos(struct Node **head, int position) {
    if (*head == NULL || position <= 0) {
        return;
    }
    struct Node *temp = *head,*prev=NULL;
    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }


    for(int i=0;i<position && temp!=NULL;i++)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }
    prev->next=temp->next;
    free(temp);
}

    int main()
    {
    int size, arr[100], value, pos, data;
    printf("enter size of linked list =\n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *head = createlinkedlist(arr, size);

    printf("original linked list =\n");
    printlist(head);
    printf("\n");

        int position;
    printf("delete from position: ");
    scanf("%d", &position);
    delete_pos(&head, position);
    printlist(head);
    printf("\n");

    }