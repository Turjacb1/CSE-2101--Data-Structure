
#include <stdio.h>

#define N 4

#define INFINITY 99999

void print(int P[][N]);




void Warshall(int P[][N])
{

    int i, j, k;

    for (k = 0; k < N; k++) {
       
        for (i = 0; i < N; i++) {
            
            for (j = 0; j < N; j++) {
                
                if (P[i][k] + P[k][j] < P[i][j])
                    P[i][j] = P[i][k] + P[k][j];
            }
        }
    }

    
    print(P);
}








void print(int P[][N])
{
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (P[i][j] == INFINITY)
                printf("%7s", "INFINITY");
            else
                printf("%7d", P[i][j]);
        }
        printf("\n");
    }
}





int main()
{
    
    int graph[N][N] = { { 0, 5, INFINITY, 10 },
                        { INFINITY, 0, 3, INFINITY },
                        { INFINITY, INFINITY, 0, 1 },
                        { INFINITY, INFINITY, INFINITY, 0 } };

   
    Warshall(graph);
    return 0;
}