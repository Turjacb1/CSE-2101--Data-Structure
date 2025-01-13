// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 100 

// int graph[MAX][MAX];
// int n = 0; 




// void insertNode() {
//     n++;
//     for (int i = 0; i < n; i++) {
//         graph[i][n - 1] = 0;
//         graph[n - 1][i] = 0;
//     }
// }




// void insertEdge(int src, int dest, int isDirected) {
//     if (src >= n || dest >= n) {
//         printf("Invalid edge!\n");
//         return;
//     }


//     graph[src][dest] = 1;
//     if (!isDirected) {
//         graph[dest][src] = 1;
//     }
// }




// void displayGraph() {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", graph[i][j]);
//         }
//         printf("\n");
//     }
// }



// int main() {
//     insertNode();
//     insertNode();
//     insertEdge(0, 1, 0); 
//     insertNode();
//     insertEdge(1, 2, 1); 

//     printf("Adjacency Matrix:\n");
//     displayGraph();
//     return 0;
// }



#include<stdio.h>
#include<stdlib.h>

#define max 100

int graph[max][max];

int n=0;

int main()
{
    insertnode();
    insertnode();
    insertedge(0,1,0);
    insertnode();
    insertedge(1,2,1);

    displaygraph();
}


void insertnode()
{
    n++;
    for(int i=0;i<n;i++)
    {
        graph[i][n-1]=0;
        graph[n-1][i]=0;
    }
}


void insertedge(int srt,int dest,int isdirected)
{
    if(srt>=n || dest >=n)
    {
        printf("invaild edge");
        return;
    }

    graph[srt][dest]=1;

    if(!isdirected)

{
    graph[dest][srt]=1;
}


}




void displaygraph()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
       
       printf("%d ",graph[i][j]);


        }
        printf("\n");
    }
}