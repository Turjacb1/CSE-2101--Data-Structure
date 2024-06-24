#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *create_circular_linked_list(int arr[], int size) {
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
            current = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }

    if (current != NULL) {
        current->next = head; 
    }

    return head;
}

void print_circular_list(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

struct Node* insert_at_beginning(struct Node *head, int value) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = value;

    if (head == NULL) {
        newnode->next = newnode; 
        head = newnode;
    } else {
        struct Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
       newnode->next = head;
        temp->next = newnode;
        head = newnode;

        
       

    }

    return head;
}

int main() {
    int elements;
    int arr[100];

    printf(" elements size: ");
    scanf("%d", &elements);

    printf("Enter the elements: ");
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *head = create_circular_linked_list(arr, elements);

    printf("Original list: \n");
    print_circular_list(head);

    int value;
    printf(" value to insert: ");
    scanf("%d", &value);

    head = insert_at_beginning(head, value);

    printf(" after insertion in beginning: \n");
    print_circular_list(head);

    return 0;
}
