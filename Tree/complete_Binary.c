// #include <stdio.h>
// #include <stdlib.h>




// // Structure for a tree node
// struct Node {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };



// // Function to create a new tree node
// struct Node* newNode(int data) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->data = data;
//     node->left = NULL;
//     node->right = NULL;
//     return node;
// }




// // Function to insert nodes in level order
// struct Node* insertLevelOrder(int arr[], int i, int n) {
//     struct Node* root = NULL;

//     // Base case for recursion
//     if (i < n) {
//         root = newNode(arr[i]);

//         // Insert left child
//         root->left = insertLevelOrder(arr, 2 * i + 1, n);

//         // Insert right child
//         root->right = insertLevelOrder(arr, 2 * i + 2, n);
//     }
//     return root;
// }







// // Function to print the tree in level order (using a queue)
// void printLevelOrder(struct Node* root) {
//     if (root == NULL) return;

//     struct Node* queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = root;

//     while (front < rear) {
//         struct Node* current = queue[front++];
//         printf("%d ", current->data);

//         if (current->left != NULL) {
//             queue[rear++] = current->left;
//         }
//         if (current->right != NULL) {
//             queue[rear++] = current->right;
//         }
//     }
// }





// int main() {
//     int arr[] = {1, 2, 3, 4, 5, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     struct Node* root = insertLevelOrder(arr, 0, n);

//     printf("Level order traversal of complete binary tree: ");
//     printLevelOrder(root);
//     printf("\n");

//     return 0;
// }







#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};



// Function to create a new node
struct Node* newnode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}



// Function to insert nodes in level order
struct Node* insertlevelorder(int arr[], int a, int n) {
    struct Node* root = NULL;
    if (a < n) {
        root = newnode(arr[a]);
        root->left = insertlevelorder(arr, 2 * a + 1, n);
        root->right = insertlevelorder(arr, 2 * a + 2, n);
    }
    return root;
}





// Function to print level order traversal of a tree
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
    struct Node* root = insertlevelorder(arr, 0, n);

    printlevelorder(root);

    return 0;
}
