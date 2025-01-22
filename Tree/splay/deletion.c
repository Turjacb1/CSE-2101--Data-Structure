#include <stdio.h>
#include <stdlib.h>




// Node structure for a splay tree
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;



// Function to create a new node
Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}



// Right rotation
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}



// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}



// Splay operation
Node* splay(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key) {
        if (root->left == NULL) return root;
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        } else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }
        return (root->left == NULL) ? root : rightRotate(root);
    } else {
        if (root->right == NULL) return root;
        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        } else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }
        return (root->right == NULL) ? root : leftRotate(root);
    }
}



// Insert operation
Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);
    root = splay(root, key);
    if (root->key == key) return root;

    Node* newnode = newNode(key);
    if (key < root->key) {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    } else {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }
    return newnode;
}


// Function to delete a key from the splay tree
Node* deleteKey(Node* root, int key) {
    if (root == NULL) return NULL;

    root = splay(root, key);
    if (root->key != key) return root;

    Node* temp;
    if (root->left == NULL) {
        temp = root;
        root = root->right;
    } else {
        temp = root;
        root = splay(root->left, key);
        root->right = temp->right;
    }

    free(temp);
    return root;
}



// Preorder traversal of the tree
void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}



// Main function to test the splay tree deletion
int main() {
    Node* root = NULL;

    root = newNode(100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

    printf("Preorder traversal of the splay tree before deletion:\n");
    preOrder(root);
    printf("\n");


    root = deleteKey(root, 50);
    printf("Preorder traversal of the splay tree after deleting 50:\n");
    preOrder(root);
    printf("\n");

    root = deleteKey(root, 20);
    printf("Preorder traversal of the splay tree after deleting 20:\n");
    preOrder(root);
    printf("\n");

    return 0;
}
