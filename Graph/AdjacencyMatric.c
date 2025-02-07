#include <stdio.h>

int main()
{
int input[7][2]={{0,1},{0,2},{0,3},{1,3},{1,4},{3,4},{2,3}};

int nov=5;
int noe=7;
int graph[7][7]={0};
for(int i=0;i<noe;i++)
{
    int v1=input[i][0];
    int v2=input [i][1];
    graph[v1][v2]=1;
    graph[v2][v1]=1;
}
for(int v1=0;v1<nov;v1++)
{
    printf("%d:",v1);
    for(int v2=0;v2<nov;v2++)
    {
        if(graph[v1][v2]==1)
            printf("%d ",v2);
    }
    printf("\n");
}
    return 0;
}
