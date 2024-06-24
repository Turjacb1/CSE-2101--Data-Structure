
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

void delete_specificdata(struct Node **head, int data) {
    if (*head == NULL) {
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (prev == NULL) {
        *head = (*head)->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}




void printlist(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}




int main() {
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


 printf("delete specific data =");
    scanf("%d", &data);

    printf("after deletin specific value = ");
    delete_specificdata(&head, data);
    printlist(head);
    printf("\n");

}