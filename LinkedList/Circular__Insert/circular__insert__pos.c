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
            printf("allocation failed\n");
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

    // Make the list circular
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

    printf("(back to head: %d)\n", head->data);
}

void insert_middle(struct Node *head, int position, int value) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    struct Node *temp = head;
    int counter = 0;

    if (position == 0) {//if pos is  beg
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = head;

        //if pos is last node
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = new_node;
        new_node->next = head;

        
        *head = *new_node;
        return;
    }

   //inert pos
    while (counter < position - 1 && temp->next != head) {
        counter++;
        temp = temp->next;
    }

    if (counter != position - 1 || temp->next == head) {
        printf("Invalid position\n");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = temp->next;
    temp->next = new_node;
}

int main() {
    int elements;
    int arr[100]; 

    printf("Enter the number of elements size: ");
    scanf("%d", &elements);

    printf("Enter the elements: ");
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *head = create_circular_linked_list(arr, elements);

    printf("Original list: \n");
    print_circular_list(head);

    int position, value;
    printf(" position: ");
    scanf("%d", &position);

    printf(" value to insert: ");
    scanf("%d", &value);

    insert_middle(head, position, value);

    printf("t after insertion: \n");
    print_circular_list(head);

    return 0;
}
