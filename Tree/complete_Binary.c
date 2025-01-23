







#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};




struct Node* newnode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}




struct Node* levelorder(int arr[], int a, int n) {
    struct Node* root = NULL;
    if (a < n) {
        root = newnode(arr[a]);
        root->left = levelorder(arr, 2 * a + 1, n);
        root->right = levelorder(arr, 2 * a + 2, n);
    }
    return root;
}





void printlevelorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n");
}





int main() {
    int arr[] = {10, 20, 30, 22, 34, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* root = levelorder(arr, 0, n);

    printlevelorder(root);

    return 0;
}
