/*
A network of n locations is represented as a graph. Write a C program that accepts the graph 
using an Adjacency Matrix, accepts a starting vertex, performs a graph traversal, displays the visit 
order, and ensures that a vertex is not processed repeatedly. Test it with connected and partially 
connected graphs.*/

#include <stdio.h>

    int n, start;
    int adj[100][100];
    int visited[100] = {0};

    void dfs(int v);

int main()
{

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    printf("0 for no edge, 1 for an edge\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the starting vertex: ");
    do
    {
        scanf("%d", &start);
        if (start < 1 || start > n) 
        {
            printf("Please enter a value between 1 and %d : ", n);
        }
    }
    while (start < 1 || start > n);
    start--; // Adjusted for 0-based indexing
    dfs(start);
}

void dfs(int v) 
{
    visited[v] = 1;
    printf("%d ", v + 1);
    for (int i = 0; i < n; i++) 
    {
        if (adj[v][i] == 1 && !visited[i]) 
        {
            dfs(i);
        }
    }
}