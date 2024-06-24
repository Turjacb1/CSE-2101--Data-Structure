#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *create__doubly__linked_list(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    int i;

    for (i = 0; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));

        if (temp == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }

        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            temp->prev = NULL;
        } else {
            current->next = temp;
            temp->prev = current; 
        }

        current = temp; 
    }

    return head;
}

void print_list(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("null\n");
}




struct Node *insert_beginning(struct Node *head,int data)
{
    struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));

    if(newnode==NULL)
    {
       printf("memort allocation failed ");
       exit(1);
    }
    newnode->data=data;
    newnode->next=head;
     newnode->prev=NULL;
     head=newnode;
     return head;
}

int main() {
    int elements;
    int arr[100]; //

    printf(" elements size: ");
    scanf("%d", &elements);

    printf("Enter the elements ");
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *head = create__doubly__linked_list(arr, elements);

    printf("Original list: \n");
    print_list(head);

    int value;
    printf("enter the value : ");
    scanf("%d", &value);

    head = insert_beginning(head, value);

    printf("List after insertion: \n");
    print_list(head);

    return 0;
}
