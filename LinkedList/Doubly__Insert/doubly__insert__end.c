#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev; 
};

struct Node *create_dooubly_linked_list(int arr[], int size) {
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

    printf("null");
}

struct Node *insert_at_end(struct Node *head, int value) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("memory allocation failed");
        exit(1);
    }

    new_node->data = value;
    new_node->next = NULL;

    
    if (head == NULL) {
        new_node->prev = NULL;  
        return new_node;        
    }

   
    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

   
    temp->next = new_node;
    new_node->prev = temp;

    return head;
}

int main() {
    int elements;
    int arr[100];

    printf(" number of elements: ");
    scanf("%d", &elements);

    printf("Enter the elements: ");
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *head = create_dooubly_linked_list(arr, elements);

    printf("Original list: \n");
    print_list(head);

    int value;
    printf(" value to insert at the end: ");
    scanf("%d", &value);

    head = insert_at_end(head, value);

    printf("List after insertion: \n");
    print_list(head);
    printf("\n");

    return 0;
}
