#include <stdio.h>
#include <stdlib.h>



struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}



struct Node* insert(struct Node* node, int data) {
    
    if (node == NULL) {
        return newNode(data);
    }

   
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    
    return node;
}


struct Node* search(struct Node* root, int key) {
  
    if (root == NULL || root->data == key) {
        return root;
    }

    
    if (root->data < key) {
        return search(root->right, key);
    }

   
    return search(root->left, key);
}



int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    int key = 40;
    struct Node* result = search(root, key);
    if (result != NULL) {
        printf("key %d found =", key);
    } else {
        printf("Key %d not found .\n", key);
    }

    return 0;
}
