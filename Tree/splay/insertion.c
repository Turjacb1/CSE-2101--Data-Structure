#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;


Node* newNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// Right rot
Node* rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

// Left rot
Node* leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}



Node* splay(Node* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    // Zig 
    if (key < root->key) {
        if (root->left == NULL) return root;

        // Zig-Zig 
        if (key < root->left->key) {
            root->left->left = splay(root->left->left, key);
            root = rightRotate(root);
        }
        // Zig-Zag
        else if (key > root->left->key) {
            root->left->right = splay(root->left->right, key);
            if (root->left->right != NULL)
                root->left = leftRotate(root->left);
        }

        return (root->left == NULL) ? root : rightRotate(root);
    }
    else { // Zag case 
        if (root->right == NULL) return root;

        // Zag-Zag 
        if (key > root->right->key) {
            root->right->right = splay(root->right->right, key);
            root = leftRotate(root);
        }
        // Zag-Zig 
        else if (key < root->right->key) {
            root->right->left = splay(root->right->left, key);
            if (root->right->left != NULL)
                root->right = rightRotate(root->right);
        }

        return (root->right == NULL) ? root : leftRotate(root);
    }
}



Node* insert(Node* root, int key) {
    if (root == NULL) return newNode(key);

    root = splay(root, key);

    if (root->key == key) return root;

    Node* newnode = newNode(key);

    if (key < root->key) {
        newnode->right = root;
        newnode->left = root->left;
        root->left = NULL;
    }
    else {
        newnode->left = root;
        newnode->right = root->right;
        root->right = NULL;
    }

    return newnode;
}


void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}


int main() {
    Node* root = NULL;

    
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

    printf("Preorder traversal of the splay tree:\n");
    preOrder(root);

    return 0;
}
