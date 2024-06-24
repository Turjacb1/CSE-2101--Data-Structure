
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* create_doubly_linkedlist(int arr[], int size) {
    struct Node *head = NULL, *temp = NULL, *current = NULL;
    for (int i = 0; i < size; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
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

void printlist(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("null\n");
}

void delete_pos(struct Node** head, int pos) {
    if (*head == NULL||pos <= 0) {
        return;
    }

    struct Node *temp = *head;

    if (pos == 1) {
       
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;  
        }
        free(temp);
        return;
    }

    
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL||temp->next == NULL) {
      
        return;
    }

    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int main() {
    int size, arr[100], value, pos;
    printf("Enter size \n");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* head = createlinkedlist(arr, size);

    printf("original list \n");
    printlist(head);
    printf("\n");

    printf("Enter position  ");
    scanf("%d", &pos);

    delete_pos(&head, pos);

    printf("after deletion \n");
    printlist(head);
    

    return 0;
}


