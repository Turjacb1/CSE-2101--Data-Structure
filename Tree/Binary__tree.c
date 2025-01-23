#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left, *right;
};


struct Node *create() {
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    int x;
    printf("\nEnter data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1) {
        return NULL; 
    }
    newnode->data = x;
    printf("\n left child  %d: ", x);
    newnode->left = create(); 
    printf("\nright child %d: ", x);
    newnode->right = create(); 
    return newnode;
}


void inorderPrint(struct Node *root) {
    if (root == NULL) {
        return;
    }
    inorderPrint(root->left);         
    printf("%d\n", root->data);      
    inorderPrint(root->right);       
}

void main() {
    struct Node *root;
    root = create(); 
    printf("\nTree nodes (Inorder Traversal):\n");
    inorderPrint(root); 
}
