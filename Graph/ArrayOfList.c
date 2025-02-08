#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    struct Node*next;
}
Node*createNewNode(int gd){
    Node*newNode;
    newNode=new Node();
    new Node->next=NULL;
    new Node->data=gd;
    return newNode;
}
void CreateGraph(vector<Node*>&graph,int v1,int v2)
{
    if(graph[v1]==NULL)
    graph[v1]=createNewNode(v2);
    else
    {
        Node*curr;
        for(curr=graph[v1];curr->next;curr=curr->next);
        curr->next=createNewNode(v2);
    }
}
int main()
{
int input[7][2]={{0,1},{0,2},{0,3},{1,3},{1,4},{3,4},{2,3}};
int nov=5;
int noe=7;
vector<Node*>graph(nov,NULL);
for(int i=0;i<noe;i++)
{
    int v1=input[i][0];
    int v2=input [i][1];
    createGraph(graph,v1,v2)
    createGraph(graph,v2,v1)
}
for(int v1=0;v1<nov;v1++)
{
    printf("%d:",v1);
    for(Node*curr=graph[v1];curr;curr=curr->next))
    {
            printf("%d ",curr->data);
    }
    printf("\n");
}
    return 0;
}
