#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *circular__linkedlist(int arr[], int size)
{
    struct Node *temp = NULL, *head = NULL, *current = NULL;
    for (int i = 0; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        if (temp == NULL) {
            printf("memory allocation failed\n");
            exit(1);
        }
        temp->data = arr[i];
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            current->next = temp;
        }
        current = temp;
    }

    if (current != NULL) {
        current->next = head; 
    }

    return head;
}

void delete__beg(struct Node **head) {
    if (*head == NULL) {
        return; 
    }

    struct Node *temp = *head;
    *head = (*head)->next;  

   
    if (*head != NULL) { 
        struct Node *tail = *head;
        while (tail->next != temp) {
            tail = tail->next;
        }
        tail->next = *head;
    }

    free(temp);
}

void printlist(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("head\n");
}

int main() {
    int arr[100], size;
    printf(" size of list = ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node *head = circular__linkedlist(arr, size);
    printf("original list = ");
    printlist(head);

    delete__beg(&head);
    printf("after deleting in beginning = ");
    printlist(head);

    return 0;
}
