#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node *create_linked_list(int arr[], int size) {
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

    return head;
}




void print_list(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}



struct Node* beginning(struct Node *head, int value) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = head;
    head = new_node; 
    return head; 
}



int main() {
    int elements;
    int arr[100]; //

    printf("Enter the number of elements size: ");
    scanf("%d", &elements);

    printf("Enter the elements ");
    for (int i = 0; i < elements; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *head = create_linked_list(arr, elements);

    printf("Original list: \n");
    print_list(head);

    int user_value;
    printf("Enter the value to insert: ");
    scanf("%d", &user_value);

    head = beginning(head, user_value); 

    printf("List after insertion: \n");
    print_list(head);

    return 0;
}
