#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];
int n = 0; 



Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}


void insertNode() {
    adjList[n++] = NULL; 
}


void insertEdge(int src, int dest, int isDirected) {
    if (src >= n || dest >= n) {
        printf("Invalid edge!\n");
        return;
    }
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;


    if (!isDirected) {
        newNode = createNode(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }
}



void displayGraph() {
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        printf("Node %d: ", i);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main() {
    insertNode();
    insertNode();
    insertEdge(0, 1, 0); 
    insertNode();
    insertEdge(1, 2, 1);

    printf("Adjacency List:\n");
    displayGraph();
    return 0;
}
