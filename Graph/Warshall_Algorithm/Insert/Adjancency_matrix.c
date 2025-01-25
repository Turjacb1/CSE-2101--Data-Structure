
#include<stdio.h>
#include<stdlib.h>
#define max 50
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