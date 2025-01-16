#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }

    return root;
}



void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}



void preorderTraversal(struct Node* root)
{
    if(root !=NULL)
    {
        printf("%d",root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}



int main() {
    struct Node* root = NULL;
    int choice, value;

    printf("Binary Tree Operations:\n");
    printf("1. Insert a node\n");
    printf("2. Display In-Order \n");
    printf("3.Display pre-order \n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("In-Order Traversal: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("pre-order Traversal :");
                preorderTraversal(root);
                printf("\n");
                break;

                case 4:
                exit(0);

            default:
                printf("Invalid choice! \n");
        }
    }

    return 0;
}



